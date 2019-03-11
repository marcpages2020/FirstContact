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
#pragma comment(lib, "SDL_Mixer/libx86/SDL2_mixer.lib")

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char *argv[]) {
	SDL_Window *window; // we create a pointer for the window
	SDL_Renderer *render;
	SDL_Surface *background,*spaceship;
	SDL_Rect r_spaceship, r_background;
	background = IMG_Load("Assets/background.png");
	spaceship = IMG_Load("Assets/spaceship.png");
	int SDL_init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);
	Mix_Init(MIX_INIT_OGG);
	Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,MIX_DEFAULT_FORMAT,2,8);

	int x = 0;
	int y = 0;
	r_spaceship.x = 0;
	r_spaceship.y = 240;
	r_spaceship.h = 50;
	r_spaceship.w = 80;

	window = SDL_CreateWindow("MyAwesomeGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_RESIZABLE); //(position,position,size,size,flag)
	if (window == NULL) {
		cout << "Could not create window" << SDL_GetError() << endl; // in the case it cannot be created it returns null
		return 1;
	}
	render = SDL_CreateRenderer(window, -1, 0);
	SDL_Texture *background_text = SDL_CreateTextureFromSurface(render, background);
	SDL_FreeSurface(background);
	SDL_Texture *spaceship_text = SDL_CreateTextureFromSurface(render, spaceship);
	SDL_FreeSurface(spaceship);

	while (1) {
		SDL_Event event; //we create an event
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_UP:
					r_spaceship.y = r_spaceship.y - speed;
					break;
				case SDLK_DOWN:
					r_spaceship.y = r_spaceship.y + speed;
					break;
				case SDLK_RIGHT:
					r_spaceship.x = r_spaceship.x + speed;
					break;
				case SDLK_LEFT:
					r_spaceship.x = r_spaceship.x - speed;
					break;
				case SDLK_SPACE:
					//sx = x + 45;
					//sy = y + 25;
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
					//sx = sx;
					//sy = sy;
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

		//sx = sx + shotspeed;
		//SDL_SetRenderDrawColor(render, 0, 0, 100, 255); // we set the color of the render
		SDL_RenderClear(render);
		SDL_RenderCopy(render, background_text, NULL, NULL);
		SDL_RenderCopy(render, spaceship_text, NULL, &r_spaceship);
		SDL_RenderPresent(render);
	}
	SDL_DestroyWindow(window);
	SDL_DestroyTexture(background_text);
	SDL_DestroyTexture(spaceship_text);
	Mix_CloseAudio();
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
	return 0;
}

