#include "game.h"

int main(int argc, char *argv[])
{
	srand(time(NULL));

	init();

	menu();

	quit();
	return 0;
}