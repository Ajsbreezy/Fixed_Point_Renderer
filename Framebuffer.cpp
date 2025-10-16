#include "Framebuffer.h"

// Framebuffer constructor to cast data from SDL_Surface
// We must do this because we do not have access to that memory
// It lets us easily manipulate whats in SDL's pixel memory
Framebuffer::Framebuffer(SDL_Surface* surf, int w, int h) {
    surface = surf;
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
void Framebuffer::set_pixel(int x, int y, int R, int G, int B) {
    if (x < 0 || y < 0 || x > WIDTH || y  > HEIGHT) {
        std::cerr << "ERROR: Pixel not in bounds" << std::endl;
        return;
    }
    uint32_t color = RGB(R,G,B);
    pixels[WIDTH * y + x] = color;
}

uint32_t Framebuffer::RGB (uint8_t R, uint8_t G, uint8_t B) {
    return (uint32_t)SDL_MapRGB(surface->format, R, G, B);
}