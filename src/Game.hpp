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
    uint64_t last_time{};
    uint64_t current_time{};

    double dt{};

    Window::Window window;
    Renderer::Renderer renderer;
};

} // Game

#endif //GAME_HPP
