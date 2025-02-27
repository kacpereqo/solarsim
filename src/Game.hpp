//
// Created by remza on 24.02.2025.
//

#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>

#include "renderer.hpp"
#include "window.hpp"

namespace Game {

class Game {
public:
    void run();

private:
    Window::Window window;
    Renderer::Renderer renderer;
};

} // Game

#endif //GAME_HPP
