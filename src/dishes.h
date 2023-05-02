#ifndef _DISHES_H
#define _DISHES_H

// My libraries
#include "ingredients.h"
#include "customer.h"

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

	// Logic
	void addIngredient(const int &addDish, const int &addIngredient);
	int removeIngredient(const int &removeDish);

	int checkBurger(Customer *customer, const int &currentDish);

private:
	int typeIngredients[NUM_DISHES][DISHES_MAX_INGREDIENTS];
	int numIngredients[NUM_DISHES];
	Ingredients ingredients;
};


#endif