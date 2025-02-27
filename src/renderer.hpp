//
// Created by remza on 26.02.2025.
//

#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL2/SDL_render.h>
#include <vector>
#include "planet.hpp"

namespace Planet {
    class Planet;
};

namespace Renderer {

class Renderer {
private:
    SDL_Renderer* renderer{};
    std::vector<Planet::Planet*> entities;

public:
    void add_entity(Planet::Planet *entity);

    void init(SDL_Window* window);

    SDL_Renderer* get_renderer();

    void fill_rect(const SDL_Rect &rect, SDL_Color color) const;
    void fill_circle(const SDL_Point &center, uint32_t diameter, SDL_Color color) const;

    void update() const;

    SDL_Renderer* get_renderer() const;

    Renderer() = default;
    ~Renderer();
};

} // Renderer


#endif //RENDERER_HPP
