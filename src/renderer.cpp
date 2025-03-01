//
// Created by remza on 26.02.2025.
//

#include "renderer.hpp"
// #include <SDL2/SDL_test_font.h>
#include <SDL2/SDL_timer.h>
#include <iostream>
#include "planet.hpp"

namespace Renderer {

    void Renderer::init(SDL_Window *window) {
        this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        if (!this->renderer) {
            std::cout << "Error creating renderer: " << SDL_GetError() << std::endl;
            system("pause");
        }
    }

    void Renderer::fill_rect(const SDL_Rect &rect, const SDL_Color color) const {
        SDL_SetRenderDrawColor(this->renderer, color.r, color.g, color.b, color.a);
        SDL_RenderFillRect(this->renderer, &rect);
    }

    void Renderer::fill_circle(const Vec::Point &center, uint32_t diameter, const SDL_Color color) const {
        SDL_SetRenderDrawColor(this->renderer, color.r, color.g, color.b, color.a);
        for (int x = 0; x < diameter; x++) {
            for (int y = 0; y < diameter; y++) {
                const double dx = static_cast<double>(diameter) / 2.0f - x;
                const double dy = static_cast<double>(diameter) / 2.0f - y;
                if ((dx * dx + dy * dy) < (static_cast<double>(diameter) / 2) * (static_cast<double>(diameter) / 2)) {
                    (void)SDL_RenderDrawPointF(this->renderer, center.x + dx,center.y + dy);
                }
            }
        }
    }

    void Renderer::draw_line(const Vec::Point start, const Vec::Point end, const SDL_Color color) const {
        SDL_SetRenderDrawColor(this->renderer, color.r, color.g, color.b, color.a);
        SDL_RenderDrawLineF(this->renderer, start.x, start.y, end.x, end.y);
    }

    void Renderer::add_entity(Planet::Planet *entity) {
        this->entities.push_back(entity);
        std::cout << "Entity added!" << std::endl;
    }

    void Renderer::draw_vector(const Vec::Point start,  Vec::Vec2<double> vector, const SDL_Color color) const {
        vector = vector / 1000.0;
        const Vec::Point end = {start.x + vector.x, start.y + vector.y};
        this->draw_line(start, end, color);
    }

    void Renderer::update_entities() {

        for (size_t idx = 0; idx < this->entities.size(); idx++) {
            const auto entity = this->entities[idx];

            for (size_t jdx = 0; jdx < this->entities.size(); jdx++) {
                const auto inner_entity = this->entities[jdx];

                if (entity == inner_entity) continue;

                if (entity->is_colliding(inner_entity)) {
                    entity->eat_planet(inner_entity);
                    this->entities.erase(this->entities.begin() + jdx);

                    std::cout << "Collision detected!" << std::endl;
                    break;
                }

                entity->update_properties(inner_entity, this->dt);
            }
            entity->update_position(this->dt);
        }
    }

    void Renderer::update() const {

        SDL_RenderPresent(this->renderer);

        SDL_SetRenderDrawColor(this->renderer, 0,0,0,255);
        SDL_RenderClear(this->renderer);
    }

    Renderer::~Renderer() {
        SDL_DestroyRenderer(this->renderer);
    }

    [[nodiscard]] SDL_Renderer* Renderer::get_renderer() const {
        return this->renderer;
    }

    void Renderer::draw_entities() const {
        for (const auto entity : this->entities) {
            entity->draw(this);
        }
    }
} // Renderer