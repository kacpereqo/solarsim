//
// Created by remza on 27.02.2025.
//

#ifndef VEC_HPP
#define VEC_HPP
#include <cmath>
#include "units.hpp"
#include <iostream>

#include "renderer.hpp"

;

namespace Renderer {
    class Renderer;
}

namespace Vec {

    template <typename T>
    struct Vec2 {
        T x;
        T y;

        Vec2() : x(0), y(0) {}
        Vec2(const T x, const T y) : x(x), y(y) {}

        Vec2 operator+(const Vec2& other) const {
            return {x + other.x, y + other.y};
        }

        Vec2 operator-(const Vec2& other) const {
            return {x - other.x, y - other.y};
        }

        template <typename U>
        Vec2 operator*(const U scalar) const {
            return {x * scalar, y * scalar};
        }

        template <typename U>
        Vec2 operator/(const U scalar) const {
            return {x / scalar, y / scalar};
        }

        double length() const {
            return std::sqrt(x * x + y * y);
        }

        friend std::ostream& operator<<(std::ostream& os, const Vec2& vec) {
            os << "x: " << vec.x << ", y: " << vec.y;
            return os;
        }

    };

    struct Point : Vec2<double> {
        Point() : Vec2<double>{0, 0} {}
        Point(const double x, const double y) : Vec2<double>{x, y} {}

        explicit operator SDL_Point() const {
            return {static_cast<int>(x), static_cast<int>(y)};
        }

        Units::Radian angle(const Point& other) const {
            return std::atan2(other.y - y, other.x - x);
        }

        double distance(const Vec2& other) const {
            return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2)) * 1'000'000'000;
        }
    };
}

#endif //VEC_HPP
