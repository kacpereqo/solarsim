//
// Created by remza on 26.02.2025.
//

#include "planet.hpp"



namespace Planet {

    void Planet::update_position(float dt) {

        this->center.x += this->velocity.x * dt;
        this->center.y += this->velocity.y * dt;
    }

        void Planet::update_properties(const Planet * other, const float dt) {
        if (this == other) return;

        const Vec::Vec2<Units::Newton> force = this->calc_gravity_force(other);
        this->force = this->force + force;

        const Vec::Vec2<Units::MeterPerSecondSquared> acceleration = this->force / this->mass;
        this->acceleration = acceleration;

        const Vec::Vec2<Units::MeterPerSecond> velocity = this->velocity + acceleration * dt;
        this->velocity = velocity;
    }

    void Planet::draw(const Renderer::Renderer * renderer) const {
        renderer->fill_circle(this->center, this->diameter, this->color);
    }

} // Planet