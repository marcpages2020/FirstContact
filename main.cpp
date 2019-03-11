#include <iostream>
#include<time.h>
#include "SDL/include/SDL.h"
#include "SDL_image/include/SDL_image.h"
#include "SDL_mixer/include/SDL_mixer.h"

#pragma comment(lib, "SDL/SDL2.lib")
#pragma comment(lib, "SDL/SDL2main.lib")
#pragma comment(lib, "SDL_image/libx86/SDL2_image.lib")
#pragma comment(lib, "SDL_Mixer/libx86/SDL2_mixer.lib")

using namespace std;

#define speed 2;
#define shotspeed 30;
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

struct PlayerInput {
	bool pressing_up = false;
	bool pressing_down = false;
	bool pressing_right = false;
	bool pressing_left = false;
}player_input;

int main(int argc, char *argv[]) {
	SDL_Window *window; 
	SDL_Renderer *render;
	SDL_Surface *loading_surface;
	SDL_Rect spaceship, background;
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	Mix_Init(MIX_INIT_OGG);
	Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,MIX_DEFAULT_FORMAT,2,8);

	int x = 0;
	int y = 0;

	spaceship.x = 0;
	spaceship.y = 240;
	spaceship.h = 50;
	spaceship.w = 80;

	window = SDL_CreateWindow("MyAwesomeGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE); //(position,position,size,size,flag)
	if (window == NULL) {
		cout << "Could not create window" << SDL_GetError() << endl; // in the case it cannot be created it returns null
		return 1;
	}

	render = SDL_CreateRenderer(window, -1, 0);
	loading_surface = IMG_Load("Assets/background.png");
	SDL_Texture *background_text = SDL_CreateTextureFromSurface(render, loading_surface);
	SDL_FreeSurface(loading_surface);
	loading_surface = IMG_Load("Assets/spaceship.png");
	SDL_Texture *spaceship_text = SDL_CreateTextureFromSurface(render, loading_surface);
	SDL_FreeSurface(loading_surface);

	while (1) {
		SDL_Event event; //we create an event
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_UP:
					player_input.pressing_up = true;
					break;
				case SDLK_DOWN:
					player_input.pressing_down = true;
					break;
				case SDLK_RIGHT:
					player_input.pressing_right = true;
					break;
				case SDLK_LEFT:
					player_input.pressing_left = true;
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
					player_input.pressing_up = false;
					break;
				case SDLK_DOWN:
					player_input.pressing_down = false;
					break;
				case SDLK_RIGHT:
					player_input.pressing_right = false;
					break;
				case SDLK_LEFT:
					player_input.pressing_left = false;
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
		if ((player_input.pressing_up==true)&&(spaceship.y>=0))
		{
			spaceship.y -= speed;
		}else if ((player_input.pressing_down == true)&& (spaceship.y <= (SCREEN_HEIGHT - spaceship.h)))
		{
			spaceship.y += speed;
		}else if ((player_input.pressing_right == true)&&(spaceship.x<=(SCREEN_WIDTH-spaceship.w)))
		{
			spaceship.x += speed;
		}else if ((player_input.pressing_left == true) && (spaceship.x >0))
		{
			spaceship.x -= speed;
		}
		//sx = sx + shotspeed;
		//SDL_SetRenderDrawColor(render, 0, 0, 100, 255); // we set the color of the render
		SDL_Delay(2);
		SDL_RenderClear(render);
		SDL_RenderCopy(render, background_text, NULL, NULL);
		SDL_RenderCopy(render, spaceship_text, NULL, &spaceship);
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


