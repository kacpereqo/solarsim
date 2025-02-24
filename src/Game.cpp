//
// Created by remza on 24.02.2025.
//

#include <iostream>
#include "game.hpp"

namespace Game {
    void Game::run() {
        window.init();

        SDL_Event e;
        bool quit = false;
        while ( !quit ) {
            while ( SDL_PollEvent( &e ) != 0 ) {
                if ( e.type == SDL_QUIT ) {
                    quit = true;
                }
            }
        }
    }
}
