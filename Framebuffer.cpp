#include "Framebuffer.h"

// Framebuffer constructor to cast data from SDL_Surface
// We must do this because we do not have access to that memory
// It lets us easily manipulate whats in SDL's pixel memory
Framebuffer::Framebuffer(SDL_Surface* surface, int w, int h) {
    pixels = (uint32_t*)surface->pixels;
    WIDTH = w;
    HEIGHT = h;
}

// reset our screen to blank (transparent)
void Framebuffer::reset_screen() {
    if (pixels == nullptr) {
        std::cerr << "ERROR: in reset_screen; pixels is nullptr" << std::endl;
        return;
    } else {
        memset(pixels, 0, 4 * WIDTH * HEIGHT);
    }
}

// allows us to set a pixel with specific coordinates
// this functions because we compress our 2d array into 
// a 1d array which for every one y we have to skip by row length
void Framebuffer::set_pixel(uint32_t color, int x, int y) {
    pixels[WIDTH * y + x] = color;
}