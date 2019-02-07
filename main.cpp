#include"game.h"
#include <iostream>

using namespace std; 

game* Game = nullptr; 

int main(int argc, char* argv[])
{
	const int FPS = 60;
	const int FrameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime; 
	Game = new game(); 
	Game->init("Tahoor", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false); 
	while (Game->running())
	{

		frameStart = SDL_GetTicks();

		Game->handleEvents();
		Game->update();
		Game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (FrameDelay > frameTime)
		{
			SDL_Delay(FrameDelay - frameTime);
		}
	}
	Game->clean(); 
	system("pause");
	return 0; 
}

