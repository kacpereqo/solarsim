#include <iostream>
#include "game.hpp"

#include <chrono>
#include <SDL2/SDL_timer.h>
#include "planet.hpp"
#include <SDL2/SDL_ttf.h>

constexpr double TARGET_FPS = 60.0;

constexpr int FONT_HEIGHT = 24;



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

        double dt = 0.0f;

        while ( true ) {

            last = now;
            dt = static_cast<double>(SDL_GetPerformanceCounter() - last) / static_cast<double>(SDL_GetPerformanceFrequency());
            if (dt < 1 / TARGET_FPS) continue;
            now = SDL_GetPerformanceCounter();

            while ( SDL_PollEvent( &e ) != 0 ) {
                if ( e.type == SDL_QUIT ) {
                    return;
                }
            }

            renderer.set_time_multiplier(40.0);
            renderer.set_dt(dt);

            renderer.update_entities();
            renderer.draw_entities();
            renderer.update();
        }
    }
}
