#include <iostream>
#include<time.h>
#include "SDL/include/SDL.h"
using namespace std;
#define speed 20;
#define shotspeed 30;
#pragma comment(lib, "SDL/SDL2.lib")
#pragma comment(lib, "SDL/SDL2main.lib")

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char *argv[]) {
	srand(time(NULL));

	SDL_Window *window;
	SDL_Renderer *render;
	int SDL_init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("RedBox", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_RESIZABLE);
	if (window == NULL) {
		cout << "Could not creat window" << SDL_GetError() << endl;
		return 1;
	}

	int x = 0;
	int y = 0;
	int sx = 0;
	int sy = 0;
	int multx = 2;
	int multy = 2;

	while (1) {
		SDL_Event event;
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
					sx = x+45;
					sy = y + 25;
					break;
				case SDLK_ESCAPE:
					return 0;
				/*case (SDLK_LEFT&&SDLK_RIGHT):
					x = x;
					break;
				case (SDLK_DOWN && SDLK_UP):
					y = y;
					break;
					*/
				default:
					break;
				}
				break;
			case SDL_KEYUP:
				switch (event.key.keysym.sym) {
				case SDLK_UP:
					y =y;
					break;
				case SDLK_DOWN:
					y = y;
					break;
				case SDLK_RIGHT:
					x = x;
					break;
				case SDLK_LEFT:
					x = x ;
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
		render = SDL_CreateRenderer(window, -1, 0);
		SDL_SetRenderDrawColor(render, 0, 0, 100, 255);
		SDL_RenderClear(render);
		SDL_Rect rectangle;
		rectangle.x = x;
		rectangle.y = y;
		rectangle.w = 75;
		rectangle.h = 50;
		SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
		SDL_RenderFillRect(render, &rectangle);
		SDL_Rect shot;
		shot.x = sx;
		shot.y = sy;
		shot.w = 10;
		shot.h = 5;
		SDL_SetRenderDrawColor(render, 0, 200, 50, 255);
		SDL_RenderFillRect(render, &shot);
		SDL_RenderPresent(render);
		SDL_DestroyRenderer(render);
	}
	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
