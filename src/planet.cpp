//
// Created by remza on 26.02.2025.
//

#include "planet.hpp"



namespace Planet {

    void Planet::update_position() {
        ;
    }

    void Planet::update_properties() {
        ;
    }

    void Planet::draw(const Renderer::Renderer * renderer)  {
        renderer->fill_circle(center, diameter, color);
    }

} // Planet