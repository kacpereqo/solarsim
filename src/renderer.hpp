//
// Created by remza on 26.02.2025.
//

#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL2/SDL_render.h>
#include <vector>
#include "planet.hpp"
#include "vec.hpp"

namespace Planet {
    class Planet;
};

namespace Renderer {

class Renderer {
private:
    SDL_Renderer* renderer{};
    std::vector<Planet::Planet*> entities;
    double dt{};

public:
    void add_entity(Planet::Planet *entity);

    void init(SDL_Window* window);

    void fill_rect(const SDL_Rect &rect, SDL_Color color) const;
    void fill_circle(const Vec::Point &center, uint32_t diameter, SDL_Color color) const;
    void draw_line(const Vec::Point start, const Vec::Point end, SDL_Color color) const;
    void draw_vector(const Vec::Point start, Vec::Vec2<double> vector, SDL_Color color) const;

    void set_dt(const double dt) {
        this->dt = dt;
    }
    void update_entities();
    void draw_entities() const;
    void update() const;

    SDL_Renderer* get_renderer() const;

    Renderer() = default;
    ~Renderer();
};

} // Renderer


#endif //RENDERER_HPP
