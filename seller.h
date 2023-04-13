#ifndef _SELLER_H
#define _SELLER_H

// C++ libraries
#include <iostream>
// SDL libraries
#include <SDL.h>
#include <SDL_image.h>
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

	// Load
	void loadTexture(SDL_Renderer *renderer);

	// Handle event
	void handleEvent(SDL_Renderer *renderer, SDL_Event &event);

	// Get
	int getDishPosition();

	// Render
	void render(SDL_Renderer *renderer);
	void renderIngredients(SDL_Renderer *renderer, const int &posX, const int &posY, const int &type);
	void renderDeque(SDL_Renderer *renderer);

	// Logic
	void addBottomIngredient(const int &addIngredient);
	int removeBottomIngredient();

	void addTopIngredient();

	void move();

private:
	int posX, posY, cur, position;
	int status;
	Texture goRight, goLeft, stand;
	int ingredients[SELLER_MAXINGREDIENTS];
};
#endif
