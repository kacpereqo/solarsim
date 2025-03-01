//
// Created by remza on 26.02.2025.
//

#ifndef PLANET_HPP
#define PLANET_HPP
#include <SDL2/SDL_rect.h>
#include "renderer.hpp"
#include "units.hpp"
#include "vec.hpp"
#include <vector>

namespace Renderer {
    class Renderer;
}

namespace Planet {

class Planet {
private:
    Vec::Point center{};
    Units::Meter diameter{};
    SDL_Color color{};
    size_t tick{0};

    Units::Kilogram mass{};

    Vec::Vec2<Units::Newton> force{};
    Vec::Vec2<Units::MeterPerSecond> velocity{};
    Vec::Vec2<Units::MeterPerSecondSquared> acceleration{};
    std::vector<Vec::Point> path{};

public:
    Vec::Vec2<Units::Newton> calc_gravity_force(const Planet * other) const {
        constexpr double GRAVIATION_CONSTANT = 6.67430e-11f;

        const Units::Meter distance = this->center.distance(other->center);
        const Units::Radian angle = this->center.angle(other->center);

        const Units::Newton force = GRAVIATION_CONSTANT * this->mass * other->mass / (distance * distance);

        const Units::Newton x = force * std::cos(angle);
        const Units::Newton y = force * std::sin(angle);

        return {x, y};
    }
    double get_diameter() const {
        return this->diameter;
    }

    bool is_colliding(const Planet * other) const {
        return this->center.distance(other->center) < this->diameter / 2 + other->diameter / 2;
    }

    void eat_planet(const Planet * other) {
        this->diameter += other->diameter;

        const Vec::Vec2<double> this_momentum = this->velocity * this->mass;
        const Vec::Vec2<double> other_momentum = other->velocity * other->mass;

        const Vec::Vec2<double> new_velocity = (this_momentum + other_momentum) / (this->mass + other->mass);
        this->velocity = new_velocity;

        std::cout << new_velocity << std::endl;

        this->mass += other->mass;
    }

    Units::Kilogram get_mass() const {
        return this->mass;
    }

    Vec::Point get_center() const {
        return this->center;
    }

    Planet(Vec::Point center, Units::Meter diameter, const SDL_Color color, Units::Kilogram mass, Vec::Vec2<Units::MeterPerSecond> velocity = {0,0})
            : center(center), diameter(diameter), color(color), mass(mass), velocity(velocity) {}

    void update_properties(const Planet * other, double dt);
    void update_position(double dt);

    void draw(const Renderer::Renderer * renderer) const;
};

} // Planet

#endif //PLANET_HPP
