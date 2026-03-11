#pragma once

#include <memory>
#include <vector>

#include "Hittable.h"

class HittableList : Hittable {
public:
    HittableList();
    HittableList(std::vector<std::shared_ptr<Hittable>> objects);

    void clear();
    void push_back(std::shared_ptr<Hittable> object);
    bool hit(const Ray& r, double ray_t_min, double ray_t_max,
             HitRecord& rec) const override;

private:
    std::vector<std::shared_ptr<Hittable>> m_objects;
};