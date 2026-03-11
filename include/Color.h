#pragma once

#include <iostream>

#include "Vec3.h"

using Color = Vec3;

inline void write_color(const Color& pixel_color) {
    auto r{pixel_color.x()};
    auto g{pixel_color.y()};
    auto b{pixel_color.z()};

    auto rbyte{static_cast<int>(255.999 * r)};
    auto gbyte{static_cast<int>(255.999 * g)};
    auto bbyte{static_cast<int>(255.999 * b)};

    std::cout << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}