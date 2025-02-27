//
// Created by remza on 24.02.2025.
//

#include "window.hpp"
#include "iostream"
#include <cassert>

namespace Window {
    void Window::init() {
        if ( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) {
            std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
            system("pause");
        }

        this->window = SDL_CreateWindow( TITLE,
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            WIDTH,
            HEIGHT,
            SDL_WINDOW_SHOWN );

        if ( !this->window ) {
            std::cout << "Error creating window: " << SDL_GetError()  << std::endl;
            system("pause");
        }
    }

    SDL_Window *Window::get_window() const {
        assert(window != nullptr);
        return window;
    }

    Window::~Window() {
        SDL_DestroyWindow(window);
        SDL_Quit();
    }




}