#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

int main(int argc, char * args[])
{
	if (--argc == 0)
	{
		std::cout << "Invalid command usage. imgviewer {file.ext}\n";
		return 1;
	}
	SDL_Init(SDL_INIT_VIDEO);
	++args;

	char * title = args[0];
	auto wnd = SDL_CreateWindow(title, 0, 0, 640, 480, 0); 
	auto rnd = SDL_CreateRenderer(wnd, -1, SDL_RENDERER_ACCELERATED);
	
	SDL_DisplayMode dm;
	SDL_GetCurrentDisplayMode(0, &dm);
	int w = dm.w;
	int h = dm.h;

	SDL_Surface * surf = IMG_Load(title);
	SDL_Texture * tex = SDL_CreateTextureFromSurface(rnd, surf);
	SDL_FreeSurface(surf);

	int img_w = surf->w, img_h = surf->h;

	while (img_w > w || img_h > h)
	{
		img_w /= 2;
		img_h /= 2;
	}

	SDL_SetWindowSize(wnd, img_w, img_h);	
	SDL_Event event;
	while (true)
	{
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT)
		{
			break;
		}
		SDL_RenderCopy(rnd, tex, NULL, NULL);
		SDL_RenderPresent(rnd);
	}

	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(rnd);
	SDL_DestroyWindow(wnd);
	return 0;
}
