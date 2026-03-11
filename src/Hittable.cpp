#include <cmath>

#include "Hittable.h"

void HitRecord::set_face_normal(const Ray& r, const Vec3& outward_normal) {
    const auto front_face{dot(r.direction(), outward_normal) < 0};
    // either ray is inside the sphere or outside.
    m_normal = front_face ? outward_normal : -outward_normal;
}

Sphere::Sphere() : m_center{}, m_radius{} {};

Sphere::Sphere(const Vec3& center, double radius)
    : m_center{center}, m_radius{std::fmax(0, radius)} {}

bool Sphere::hit(const Ray& r, double ray_t_min, double ray_t_max, HitRecord& rec) const {
    Vec3 oc{m_center - r.origin()};
    auto a{r.direction().length_squared()};
    auto h{dot(r.direction(), oc)};
    auto c{oc.length_squared() - m_radius * m_radius};
    auto discriminant{h * h - a * c};

    if (discriminant < 0)
        return false;

    auto sqrt_d{std::sqrt(discriminant)};

    auto root{(h - sqrt_d) / a};
    if (root < ray_t_min || root >= ray_t_max) {
        root = (h + sqrt_d) / a;
        if (root < ray_t_min || root >= ray_t_max)
            return false;
    }

    rec.m_time = root;
    rec.m_point = r.at(rec.m_time);
    Vec3 outward_normal{(rec.m_point - m_center) / m_radius};
    rec.set_face_normal(r, outward_normal);

    return true;
}