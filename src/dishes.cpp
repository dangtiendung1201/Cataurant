#include "dishes.h"

// Constructor and destructor
Dishes::Dishes()
{
	for (int i = 0; i < NUM_DISHES; i++)
	{
		for (int j = 0; j < DISHES_MAX_INGREDIENTS; j++)
		{
			typeIngredients[i][j] = NOTHING;
		}
	}
}

Dishes::~Dishes()
{
	for (int i = 0; i < NUM_DISHES; i++)
	{
		for (int j = 0; j < DISHES_MAX_INGREDIENTS; j++)
		{
			typeIngredients[i][j] = NOTHING;
		}
	}
}

// Init and reset
void Dishes::init()
{
	for (int i = 0; i < NUM_DISHES; i++)
	{
		typeIngredients[i][0] = UP_BREAD;
		numIngredients[i] = 1;
	}
}

void Dishes::reset(const int &currentDish)
{
	for (int i = 0; i < DISHES_MAX_INGREDIENTS; i++)
	{
		typeIngredients[currentDish][i] = NOTHING;
	}
	numIngredients[currentDish] = 1;
	typeIngredients[currentDish][0] = UP_BREAD;
}

// Get
int Dishes::getNumIngredients(const int &currentDish)
{
	return numIngredients[currentDish];
}

// Render
void Dishes::render(SDL_Renderer *renderer)
{
	for (int i = 0; i < NUM_DISHES; i++)
	{
		for (int j = 0; j < numIngredients[i]; j++)
		{
			ingredients.render(renderer, DISHES_POSX[i], DISHES_POSY - INGREDIENTS_DISTANCE * j, typeIngredients[i][j]);
		}
	}
}

// Logic
/***
	Args:
		addDish (int): dish to add ingredient
		addIngredient (int): ingredient to add
	Returns:
		None
***/
void Dishes::addIngredient(const int &addDish, const int &addIngredient)
{
	typeIngredients[addDish][numIngredients[addDish]] = addIngredient;
	numIngredients[addDish]++;
}

/***
	Args:
		removeDish (int): dish to remove ingredient
	Returns:
		int: ingredient removed
***/
int Dishes::removeIngredient(const int &removeDish)
{
	int removeIngredient = typeIngredients[removeDish][numIngredients[removeDish] - 1];
	typeIngredients[removeDish][numIngredients[removeDish] - 1] = NOTHING;
	numIngredients[removeDish]--;
	return removeIngredient;
}

/***
	Args:
		currentDish (int): dish to check
	Returns:
		int: customer index if burger is done, -1 if not
***/
int Dishes::checkBurger(const int &currentDish)
{
	for (int i = 0; i < NUM_CUSTOMERS; i++)
	{
		if (customer[i].getStatus() != WAITING)
			continue;

		int num = customer[i].getNumRequests();
		if (num != numIngredients[currentDish])
			continue;
		int *list = customer[i].getRequestList();
		bool done = true;
		for (int j = 0; j < num; j++)
		{
			if (list[j] != typeIngredients[currentDish][j])
			{
				done = false;
				break;
			}
		}
		if (done)
		{
			customer[i].setStatus(LEAVING);
			reset(currentDish);
			return i;
		}
	}
	return -1;
}