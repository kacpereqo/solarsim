#include <iostream>
#include <SDL2/SDL.h>

constexpr int HEIGHT = 720;
constexpr int WIDTH = 1280;
constexpr char TITLE[] = "Example";

int main(int, char**) {

    SDL_Surface* winSurface = nullptr;
    SDL_Window* window = nullptr;

    if ( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) {
        std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
        system("pause");
        return 1;
    }

    window = SDL_CreateWindow( TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN );

    if ( !window ) {
        std::cout << "Error creating window: " << SDL_GetError()  << std::endl;
        system("pause");
        return 1;
    }

    winSurface = SDL_GetWindowSurface( window );

    if ( !winSurface ) {
        std::cout << "Error getting surface: " << SDL_GetError() << std::endl;
        system("pause");
        return 1;
    }

    SDL_FillRect( winSurface, nullptr, SDL_MapRGB( winSurface->format, 255, 255, 255 ) );
    SDL_UpdateWindowSurface( window );

    SDL_Event e;
    bool quit = false;
    while ( !quit ) {
        while ( SDL_PollEvent( &e ) != 0 ) {
            if ( e.type == SDL_QUIT ) {
                quit = true;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

