#ifndef _DISHES_H
#define _DISHES_H

// My libraries
#include "ingredients.h"
#include "customer.h"
#include "const.h"

class Dishes
{
public:
	// Constructor and destructor
	Dishes();
	~Dishes();

	// Init and reset
	void init();
	void reset(const int &currentDish);

	// Get
	int getNumIngredients(const int &currentDish);

	// Render
	void render(SDL_Renderer *renderer);

	void renderIngredients(SDL_Renderer *renderer, const int &posX, const int &posY, const int &type);

	// Logic
	void addIngredient(const int &addDish, const int &addIngredient);
	int removeIngredient(const int &removeDish);
	
	int checkBurger(const int &currentDish);

private:
	int ingredients[NUM_DISHES][DISHES_MAX_INGREDIENTS];
	int numIngredients[NUM_DISHES];
};

extern Dishes dish;

#endif