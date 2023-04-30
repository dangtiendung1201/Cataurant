
#include "res.h"
#include "game.h"

SDL_Window *window;
SDL_Renderer *renderer;

int main(int argc, char *argv[])
{
	srand(time(NULL));

	if (init(window, renderer))
		load(renderer);

	gameState = MENU;
	manageState(renderer);

	quit(window, renderer);
	return 0;
}