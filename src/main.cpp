#include <iostream>

int main() {
    int img_w{256};
    int img_h{256};

    // header
    std::cout << "P3\n" << img_w << ' ' << img_w << "\n255\n";

    for (int j{}; j < img_h; ++j) {
        std::clog << "\rScanlines remaining: " << (img_h - j) << ' ' << std::flush;
        for (int i{}; i < img_w; ++i) {
            auto r{static_cast<double>(i) / (img_w - 1)};
            auto g{static_cast<double>(j) / (img_h - 1)};
            auto b{0.0};

            int ir{static_cast<int>(255.999 * r)};
            int ig{static_cast<int>(255.999 * g)};
            int ib{static_cast<int>(255.999 * b)};

            std::cout << ir << ' ' << ig << ' ' << ib << ((i == img_h) ? '\t' : ' ');
        }
    }
    std::clog << "\rDone.                 \n";
}