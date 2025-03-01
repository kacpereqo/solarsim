//
// Created by remza on 26.02.2025.
//

#include "planet.hpp"



namespace Planet {

    void Planet::update_position(const double dt) {
        this->tick++;

        if (this->tick % 10) {
            this->path.push_back(this->center);
        }

        if (this->path.size() > 50) {
            this->path.erase(this->path.begin());
        }

        this->center.x += this->velocity.x * dt;
        this->center.y += this->velocity.y * dt;
    }

        void Planet::update_properties(const Planet * other, const double dt) {
        if (this == other) return;

        const Vec::Vec2<Units::Newton> force = this->calc_gravity_force(other);
        this->force = force;

        const Vec::Vec2<Units::MeterPerSecondSquared> acceleration = this->force / this->mass;
        this->acceleration = acceleration;

        const Vec::Vec2<Units::MeterPerSecond> velocity = this->velocity + acceleration * dt;
        this->velocity = velocity;
    }

    void Planet::draw(const Renderer::Renderer * renderer) const {
        constexpr bool DRAW_VECTORS = true;

        for (size_t idx = 0; idx < this->path.size() - 1; idx++) {
            renderer->draw_line(this->path[idx], this->path[idx + 1], {255, 255, 255}); // white
        }

        if (DRAW_VECTORS) {
            renderer->draw_vector(this->center, this->force / 10e20, {255, 0, 0}); // red
            renderer->draw_vector(this->center, this->velocity, {0, 255, 0}); // green
            renderer->draw_vector(this->center, this->acceleration, {0, 0, 255}); // bleu
        }

        renderer->fill_circle(this->center, this->diameter, this->color);
    }
} // Planet