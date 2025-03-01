#include <iostream>
#include "game.hpp"

#include <chrono>
#include <SDL2/SDL_timer.h>
#include <cmath>

#include "planet.hpp"

constexpr float TARGET_FPS = 300.0f;

namespace Game {
    void Game::run() {
        window.init();
        renderer.init(window.get_window());

        Planet::Planet earth = {{200,200}, 10, {0,0,255},5.972e24};
        Planet::Planet sun = {{600,400}, 20, {255,255,0},1.989e24};

        renderer.add_entity(&earth);
        renderer.add_entity(&sun);

        SDL_Event e;

        uint64_t now = SDL_GetPerformanceCounter();
        uint64_t last = 0;

        float dt = 0.0f;

        while ( true ) {

            last = now;
            now = SDL_GetPerformanceCounter();

            dt = (now - last) / static_cast<float>(SDL_GetPerformanceFrequency());

            while ( SDL_PollEvent( &e ) != 0 ) {
                if ( e.type == SDL_QUIT ) {
                    return;
                }
            }

            renderer.set_dt(dt);

            // std::cout << "FPS: " << 1.0f / dt << std::endl;

            renderer.update_entities();
            renderer.draw_entities();
            renderer.update();

        }
    }
}
