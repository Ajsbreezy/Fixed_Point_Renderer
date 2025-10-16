
#include <iostream>
#include <SDL2/SDL.h>
#include "Framebuffer.h"
// pointers to hold outputs of SDL_CreateWindow and SDL_GetWindowSurface
SDL_Window *window;
SDL_Surface *surface;
const int WIDTH = 960;
const int HEIGHT = 480;
bool quit = false;


using namespace std;
int main() {
    SDL_SetHint(SDL_HINT_VIDEO_HIGHDPI_DISABLED, "0");
    SDL_Init(SDL_INIT_VIDEO); // Initialize SDL2 window

    window = SDL_CreateWindow("FIXED POINT RENDERER", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN| SDL_WINDOW_RESIZABLE
        | SDL_WINDOW_BORDERLESS); // creating window
    surface = SDL_GetWindowSurface(window); // surface of the window initialized
    
    // Lets create a Framebuffer Object
    Framebuffer fb(surface,WIDTH, HEIGHT);
    uint32_t test = 0;

    // main loop
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }  
        }
        if (SDL_MUSTLOCK(surface)) SDL_LockSurface(surface); // lock and unlock to avoid weird errors
        fb.reset_screen();
        if (SDL_MUSTLOCK(surface)) SDL_UnlockSurface(surface);

        SDL_UpdateWindowSurface(window);
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}