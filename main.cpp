#include <iostream>
#include<time.h>
#include "SDL/include/SDL.h"
#include "SDL_image/include/SDL_image.h"
using namespace std;
#define speed 20;
#define shotspeed 30;
#pragma comment(lib, "SDL/SDL2.lib")
#pragma comment(lib, "SDL/SDL2main.lib")
#pragma comment(lib, "SDL_image/libx86/SDL2_image.lib")

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char *argv[]) {
	SDL_Window *window; // we create a pointer for the window
	SDL_Renderer *render;
	SDL_Texture *background("background.png");
	SDL_Rect r_spaceship, r_shot, r_background;
	int SDL_init(SDL_INIT_VIDEO);
	int imgFlags = IMG_INIT_PNG;

	int x = 0;
	int y = 0;
	int sx = 0;
	int sy = 0;

	window = SDL_CreateWindow("MyAwesomeGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_RESIZABLE); //(position,position,size,size,flag)
	if (window == NULL) {
		cout << "Could not create window" << SDL_GetError() << endl; // in the case it cannot be created it returns null
		return 1;
	}

	while (1) {
		SDL_Event event; //we create an event
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_UP:
					y = y - speed;
					break;
				case SDLK_DOWN:
					y = y + speed;
					break;
				case SDLK_RIGHT:
					x = x + speed;
					break;
				case SDLK_LEFT:
					x = x - speed;
					break;
				case SDLK_SPACE:
					sx = x + 45;
					sy = y + 25;
					break;
				case SDLK_ESCAPE:
					return 0;
				default:
					break;
				}
				break;
			case SDL_KEYUP:
				switch (event.key.keysym.sym) {
				case SDLK_UP:
					y = y;
					break;
				case SDLK_DOWN:
					y = y;
					break;
				case SDLK_RIGHT:
					x = x;
					break;
				case SDLK_LEFT:
					x = x;
					break;
				case SDLK_SPACE:
					sx = sx;
					sy = sy;
					break;
				case SDLK_ESCAPE:
					break;
				default:
					break;
				}
				break;
			case SDL_QUIT:
				return 0;
				break;
			}
		}

		sx = sx + shotspeed;
		render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);// (name of the window, index of rendering, flags)
		if (render == NULL) {
			cout << "Not able to create the render " << SDL_GetError();
		}
		//SDL_SetRenderDrawColor(render, 0, 0, 100, 255); // we set the color of the render
		SDL_RenderClear(render);
		SDL_RenderCopy(render, background, NULL, NULL);
		SDL_RenderPresent(render);
		SDL_Delay(500);
		SDL_FreeSurface();
	}
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
	return 0;
}

