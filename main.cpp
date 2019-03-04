#include <iostream>
#include<time.h>
#include "SDL/include/SDL.h"
using namespace std;

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
	int multx = 2;
	int multy = 2;

	while (1) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			
				x = x + multx;
				y = y + multy;
			if (x >= 565) {
				multx = -2;
			}else if (x<=0){
				multx = 2;
			}
			else if (y >= 430) {
				multy = -2;
			}
			else if (y<=0) {
				multy = 2;
			}
		}
		render = SDL_CreateRenderer(window, -1, 0);
		SDL_SetRenderDrawColor(render, 0, 0, 100, 255);
		SDL_RenderClear(render);
		SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
		SDL_Rect rectangle;
		rectangle.x = x;
		rectangle.y = y;
		rectangle.w = 75;
		rectangle.h = 50;
		SDL_RenderFillRect(render, &rectangle);
		SDL_RenderPresent(render);
		SDL_DestroyRenderer(render);
	}
	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}