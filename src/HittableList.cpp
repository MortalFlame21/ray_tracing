#include "HittableList.h"

HittableList::HittableList() : m_objects{} {}

HittableList::HittableList(std::vector<std::shared_ptr<Hittable>> objects)
    : m_objects{objects} {}

void HittableList::clear() { m_objects.clear(); }

void HittableList::push_back(std::shared_ptr<Hittable> object) {
    m_objects.push_back(object);
}

bool HittableList::hit(const Ray& r, double ray_t_min, double ray_t_max,
                       HitRecord& rec) const {
    HitRecord temp_rec{};
    bool hit_anything{};
    auto closest_so_far{ray_t_max};

    for (const auto& o : m_objects) {
        if (o->hit(r, ray_t_min, closest_so_far, temp_rec)) {
            hit_anything = true;
            closest_so_far = temp_rec.m_time;
            rec = temp_rec;
        }
    }

    return hit_anything;
}