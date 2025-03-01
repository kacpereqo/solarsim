#include <iostream>
#include "game.hpp"

#include <chrono>
#include <SDL2/SDL_timer.h>
#include "planet.hpp"
#include <SDL2/SDL_ttf.h>

constexpr double TARGET_FPS = 60.0;

constexpr int FONT_HEIGHT = 24;

double round_to_decimal(double value, int decimal_places) {
    return std::round(value * std::pow(10, decimal_places)) / std::pow(10, decimal_places);
}

namespace Game {
    void Game::run() {
        window.init();
        renderer.init(window.get_window());

        Planet::Planet earth = {{200,250}, 10, {0,0,255},5.972e24, {1.07,0.0}};
        Planet::Planet sun = {{200,400}, 20, {255,255,0},1.988e30, {0.0,0.0}};

        renderer.add_entity(&earth);
        renderer.add_entity(&sun);

        SDL_Event e;

        uint64_t now = SDL_GetPerformanceCounter();
        uint64_t last = 0;

        if (TTF_Init() < 0) {
            std::cout << "Error initializing TTF: " << TTF_GetError() << std::endl;
            return;
        }

        TTF_Font *font = TTF_OpenFont("C:/Users/remza/CLionProjects/solarsim/assets/font/lato.ttf", FONT_HEIGHT);

        if (!font) {
            std::cout << "Error loading font: " << TTF_GetError() << std::endl;
            return;
        }

        double dt = 0.0f;

        while ( true ) {

            last = now;
            dt = (SDL_GetPerformanceCounter() - last) / static_cast<double>(SDL_GetPerformanceFrequency());

            if (dt < 1 / TARGET_FPS) {
                continue;
            }

            now = SDL_GetPerformanceCounter();

            std::string fps = "FPS: " + std::to_string(round_to_decimal(1.0f / dt, 2));
            fps.resize(fps.size() - 4);

            SDL_Color color = {255, 255, 255};
            SDL_Surface *text_surface = TTF_RenderText_Solid(font, fps.c_str(), color);
            SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer.get_renderer(), text_surface);

            SDL_Rect rect = {0, 0, static_cast<int>(12 * fps.size()) , FONT_HEIGHT};
            SDL_FreeSurface(text_surface);
            SDL_RenderCopy(renderer.get_renderer(), texture, nullptr, &rect);

            while ( SDL_PollEvent( &e ) != 0 ) {
                if ( e.type == SDL_QUIT ) {
                    return;
                }
            }

            renderer.set_dt(dt*1000);

            renderer.update_entities();
            renderer.draw_entities();
            renderer.update();
        }
    }
}
