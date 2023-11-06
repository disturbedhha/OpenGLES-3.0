#include <iostream>
#include "glad.h"
#include <SDL2/SDL.h>

#ifndef WINDOW_HPP
#define WINDOW_HPP
class Window{
    public:
    SDL_Window *win;
    SDL_Renderer *render;
    SDL_GLContext context;

    Window(const int Width, const int Height);
    ~Window();
};

#endif // WINDOW_HPP