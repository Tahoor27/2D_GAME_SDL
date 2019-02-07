#include "game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include <iostream>
using namespace std; 

GameObject* player; 

GameObject*enemy;

Map*map;

SDL_Renderer* game::renderer = nullptr;

game::game()
{

}
game ::~game()
{

}
void game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0; 
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "subsystems have been initialized!" << endl; 
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			cout << "window has been created!" << endl; 
		}

		renderer = SDL_CreateRenderer(window, -1, 0); 
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			cout << "renderer has been created!" << endl;
		}
		isrunning = true; 

	}
	else
	{
		isrunning = false; 
	}
	player = new GameObject("assets/player.png",0,0);
	enemy = new GameObject("assets/enemy.png", 170, 170);
	map = new Map();
}
void game::handleEvents()
{
	SDL_Event event; 
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isrunning = false;
		break;
	default:
		break;
	}
}
void game::update()
{
	player->update();
	enemy->update();
}
void game::render()
{
	SDL_RenderClear(renderer);
	map->DrawMap();
	player->render();
	enemy->render();
	SDL_RenderPresent(renderer); 
}
void game::clean()
{
    SDL_DestroyWindow(window); 
	SDL_DestroyRenderer(renderer);
	SDL_Quit(); 
	cout << "Game cleaned!" << endl; 
}
