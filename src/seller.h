#ifndef _SELLER_H
#define _SELLER_H

// C++ libraries
#include <iostream>
// SDL libraries
#if defined(_WIN64) || defined(_WIN32)
#include <SDL.h>
#include <SDL_image.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#endif
// My libraries
#include "const.h"
#include "texture.h"
#include "ingredients.h"
#include "dishes.h"
#include "ultils.h"

class Seller
{
public:
	// Constructor and destructor
	Seller();
	~Seller();

	// Init and reset
	void init();
	void reset();

	// Handle event
	void handleEvent(SDL_Renderer *renderer, SDL_Event &event);

	// Get
	int getDishPosition();

	// Render
	void render(SDL_Renderer *renderer);
	void renderDeque(SDL_Renderer *renderer);

	// Logic
	void addBottomIngredient(const int &addIngredient);
	int removeBottomIngredient();

	void addTopIngredient();

	void move();

private:
	int posX, posY, cur, position;
	int status;
	int typeIngredients[SELLER_MAXINGREDIENTS];
};
#endif
