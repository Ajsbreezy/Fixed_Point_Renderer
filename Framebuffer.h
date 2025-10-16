#include <vector>
#include <SDL2/SDL.h>
#include <cstdint>
#include <iostream>
class Framebuffer {
    public:
    Framebuffer (SDL_Surface* surf, int w, int h); // Add width and height
    void reset_screen ();
    void set_pixel (int x, int y, int R, int G, int B);
    uint32_t RGB(uint8_t R, uint8_t G, uint8_t B);
    private:
    SDL_Surface* surface;
    uint32_t* pixels;
    int WIDTH, HEIGHT;
};
