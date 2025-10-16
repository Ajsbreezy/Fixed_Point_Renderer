#include <vector>
#include <SDL2/SDL.h>
#include <cstdint>
#include <iostream>
class Framebuffer {
    public:
    Framebuffer (SDL_Surface* surface, int w, int h); // Add width and height
    void reset_screen ();
    void set_pixel (uint32_t color, int x, int y);
    private:
    uint32_t* pixels;
    int WIDTH, HEIGHT;
};
