//
// Created by remza on 24.02.2025.
//

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>
#include <SDL2/SDL.h>
#include <expected>

namespace Window {

class Window {
private:
    SDL_Window* window = nullptr;

public:
    static constexpr int HEIGHT = 720;
    static constexpr int WIDTH = 1280;
    static constexpr char TITLE[] = "Example";

    void init();

    SDL_Window* get_window() const;

    ~Window();
};

} // window

#endif //WINDOW_HPP
