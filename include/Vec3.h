#pragma once

#include <array>
#include <iostream>

class Vec3 {
public:
    Vec3();
    Vec3(double x, double y, double z);

    double& x();
    double x() const;
    double& y();
    double y() const;
    double& z();
    double z() const;
    double length() const;
    double length_squared() const;
    double dot(const Vec3& o) const;
    Vec3 cross(const Vec3& o) const;
    Vec3 unit_vector() const;
    Vec3 operator+(const Vec3& o) const;
    Vec3 operator-(const Vec3& o) const;
    Vec3 operator*(const Vec3& o) const;
    Vec3 operator*(double t) const;
    Vec3 operator/(double t) const;
    Vec3& operator+=(const Vec3& o);
    Vec3& operator*=(double t);
    Vec3& operator/=(double t);

private:
    std::array<double, 3> m_e;
};

std::ostream& operator<<(std::ostream& out, Vec3 v);
Vec3 operator*(double t, const Vec3& o);