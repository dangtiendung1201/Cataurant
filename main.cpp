#include "game.h"

int main(int argc, char *argv[])
{
	srand(time(NULL));

	if (init())
		load();

	gameState = MENU;
	manageState();

	quit();
	return 0;
}