#include "game.h"

int main(int argc, char *argv[])
{
	srand(time(NULL));

	if (init())
		load();

	menu();

	quit();
	return 0;
}