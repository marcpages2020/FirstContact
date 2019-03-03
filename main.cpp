#include <stdio.h>
#include <iostream>
#include "SDL/include/SDL.h"

#pragma comment(lib, "SDL/x86/SDL2.lib")
#pragma comment(lib, "SDL/x86/SDL2main.lib")

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[]) {
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	window = SDL_CreateWindow("Red Box", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0, 100, 255));
	SDL_UpdateWindowSurface(window);
	SDL_Delay(2000);
	while (true == 0) {

	}
	return 0;
}

bool loadMedia(){
	bool success = true;
	return success;
}