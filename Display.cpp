#include "Display.hpp"

#include <SDL2/SDL_image.h>


Display::Display(const char * title)
{
    SDL_Init(SDL_INIT_VIDEO);
    
    wnd = SDL_CreateWindow(title, 0, 0, 640, 480, 0); 
	rnd = SDL_CreateRenderer(wnd, -1, SDL_RENDERER_ACCELERATED);
	
	SDL_DisplayMode dm;
	SDL_GetCurrentDisplayMode(0, &dm);
	int w = dm.w;
	int h = dm.h;

    SDL_Surface * surf = IMG_Load(title);
	this->tex = SDL_CreateTextureFromSurface(rnd, surf);
	SDL_FreeSurface(surf);

	int img_w = surf->w, img_h = surf->h;

	while (img_w > w || img_h > h)
	{
		img_w /= 2;
		img_h /= 2;
	}

	SDL_SetWindowSize(wnd, img_w, img_h);	
}

Display::~Display()
{
    SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(rnd);
	SDL_DestroyWindow(wnd);
}

bool Display::update()
{
    SDL_PollEvent(&event);
    SDL_RenderCopy(rnd, tex, NULL, NULL);
    SDL_RenderPresent(rnd);
    return event.type == SDL_QUIT;
}