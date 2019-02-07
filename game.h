#ifndef game_engine
#define game_engine
#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>

class game
{
public:
	game();
	~game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents(); 
	void update();
	void render();
	void clean();
	bool running()
	{
		return isrunning; 
	}

	static SDL_Renderer* renderer; 

private:
	int cnt; 
	bool isrunning; 
	SDL_Window * window; 
};







#endif // !game_engine



