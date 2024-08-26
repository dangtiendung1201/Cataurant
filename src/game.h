#ifndef _GAME_H
#define _GAME_H

// C++ libraries
#include <iostream>
#include <vector>
#include <ctime>
// SDL libraries
#if defined(_WIN64) || defined(_WIN32)
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#endif
// My libraries
#include "seller.h"
#include "customer.h"
#include "dishes.h"
#include "hungrycat.h"

class Game
{
public:
	Game();
	~Game();

	void play(SDL_Renderer *renderer);
	void menu(SDL_Renderer *renderer);
	void help(SDL_Renderer *renderer);
	void lose(SDL_Renderer *renderer);

	void gameReset();
	void menuReset();

	void processUpKey();
	void processDownKey();
	void handlePlayEvent(SDL_Renderer *renderer, SDL_Event &event);

	void setGameState(const int &state);
    int getGameState();
    void manageState(SDL_Renderer *renderer);

private:
	int gameState;

	bool musicState = ON;
	bool soundState = ON;

	Seller seller;

	Customer customer[NUM_CUSTOMERS];

	Dishes dish;

	Hungrycat hungrycat;

	bool loop = true;
};
#endif