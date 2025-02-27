#include <iostream>
#include "game.hpp"
#include <cmath>

#include "planet.hpp"

namespace Game {
    void Game::run() {
        window.init();
        renderer.init(window.get_window());

        Planet::Planet planet1({100,100}, 100, {255,255,255},1000);
        Planet::Planet planet2({200,200}, 100, {255,255,255},1000);

        renderer.add_entity(&planet1);
        renderer.add_entity(&planet2);

        SDL_Event e;

        while ( true ) {
            while ( SDL_PollEvent( &e ) != 0 ) {
                if ( e.type == SDL_QUIT ) {
                    return;
                }
            }

            renderer.update();
            SDL_Delay(1000 / 60);
        }
    }
}
