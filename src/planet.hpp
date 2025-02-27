//
// Created by remza on 26.02.2025.
//

#ifndef PLANET_HPP
#define PLANET_HPP
#include <SDL2/SDL_rect.h>
#include "renderer.hpp"

namespace Renderer {
    class Renderer;
}

namespace Planet {

class Planet {
private:
    SDL_Point center{};
    uint32_t diameter{};
    SDL_Color color{};

    uint32_t mass{};

public:
    Planet(SDL_Point center, uint32_t diameter, const SDL_Color color, uint32_t mass)
            : center(center), diameter(diameter), color(color), mass(mass) {}

    void update_properties();
    void update_position();

    void draw(const Renderer::Renderer * renderer);
};

} // Planet

#endif //PLANET_HPP
