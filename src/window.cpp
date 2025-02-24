//
// Created by remza on 24.02.2025.
//

#include "window.hpp"
#include "iostream"

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

        this->winSurface = SDL_GetWindowSurface( this->window );

        if ( !winSurface ) {
            std::cout << "Error getting surface: " << SDL_GetError() << std::endl;
            system("pause");
        }

        SDL_FillRect( winSurface, nullptr, SDL_MapRGB( winSurface->format, 255, 255, 255 ) );
        SDL_UpdateWindowSurface( window );
    }

    Window::~Window() {
        SDL_DestroyWindow(this->window);
        SDL_Quit();
    }
}