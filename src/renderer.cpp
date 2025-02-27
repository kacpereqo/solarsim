//
// Created by remza on 26.02.2025.
//

#include "renderer.hpp"
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

    void Renderer::fill_circle(const SDL_Point &center, const uint32_t diameter, const SDL_Color color) const {
        SDL_SetRenderDrawColor(this->renderer, color.r, color.g, color.b, color.a);
        for (int x = 0; x < diameter; x++) {
            for (int y = 0; y < diameter; y++) {
                const int dx = diameter / 2 - x;
                const int dy = diameter / 2 - y;
                if ((dx * dx + dy * dy) < (diameter / 2) * (diameter / 2)) {
                    SDL_RenderDrawPoint(this->renderer, center.x + dx, center.y + dy);
                }
            }
        }
    }

    void Renderer::add_entity(Planet::Planet *entity) {
        this->entities.push_back(entity);
    }

    void Renderer::update() const {
        for (const auto entity : this->entities) {

            entity->update_properties();
            entity->update_position();

            entity->draw(this);
        }

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
} // Renderer