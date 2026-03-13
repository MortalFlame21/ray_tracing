#include "Material.h"

// Start Material
bool Material::scatter([[maybe_unused]] const Ray& r,
                       [[maybe_unused]] const HitRecord& rec,
                       [[maybe_unused]] Color& attenuation,
                       [[maybe_unused]] Ray& scattered) const {
    return false;
}
// End Material

// Start Lambertian
Lambertian::Lambertian(const Color& albedo) : m_albedo{albedo} {}

bool Lambertian::scatter([[maybe_unused]] const Ray& r, const HitRecord& rec,
                         Color& attenuation, Ray& scattered) const {
    auto scatter_direction{rec.m_normal + random_unit_vector()};

    if (scatter_direction.near_zero())
        scatter_direction = rec.m_normal;

    scattered = Ray(rec.m_point, scatter_direction);
    attenuation = m_albedo;
    return true;
}
// End Lambertian

// Start Metal
Metal::Metal(const Color& albedo) : m_albedo{albedo} {}

bool Metal::scatter(const Ray& r, const HitRecord& rec, Color& attenuation,
                    Ray& scattered) const {
    auto reflected{reflect(r.direction(), rec.m_normal)};
    scattered = Ray(rec.m_point, reflected);
    attenuation = m_albedo;
    return true;
}
// End Metal