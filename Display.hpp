#pragma once
#include <SDL2/SDL.h>

class Display {
    SDL_Window * wnd;
    SDL_Renderer * rnd;
    SDL_Event event;
    SDL_Texture * tex;
public:
    Display(const char * title);
    ~Display();
    
    bool update();
};