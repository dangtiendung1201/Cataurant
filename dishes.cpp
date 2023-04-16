#include "dishes.h"

// Constructor and destructor
Dishes::Dishes()
{
	for (int i = 0; i < NUM_DISHES; i++)
	{
		for (int j = 0; j < DISHES_MAX_INGREDIENTS; j++)
		{
			ingredients[i][j] = NOTHING;
		}
	}
}

Dishes::~Dishes()
{
	for (int i = 0; i < NUM_DISHES; i++)
	{
		for (int j = 0; j < DISHES_MAX_INGREDIENTS; j++)
		{
			ingredients[i][j] = NOTHING;
		}
	}
}

// Init and reset
void Dishes::init()
{
	for (int i = 0; i < NUM_DISHES; i++)
	{
		ingredients[i][0] = UP_BREAD;
		numIngredients[i] = 1;
	}
}

void Dishes::reset(const int &currentDish)
{
	for (int i = 0; i < DISHES_MAX_INGREDIENTS; i++)
	{
		ingredients[currentDish][i] = NOTHING;
	}
	numIngredients[currentDish] = 1;
	ingredients[currentDish][0] = UP_BREAD;
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
			renderIngredients(renderer, DISHES_POSX[i], DISHES_POSY - INGREDIENTS_DISTANCE * j, ingredients[i][j]);
		}
	}
}

void Dishes::renderIngredients(SDL_Renderer *renderer, const int &posX, const int &posY, const int &type)
{
	switch (type)
	{
	case UP_BREAD:
		up_bread.render(renderer, posX, posY);
		break;
	case LETTUCE:
		lettuce.render(renderer, posX, posY);
		break;
	case BEEF:
		beef.render(renderer, posX, posY);
		break;
	case TOMATO:
		tomato.render(renderer, posX, posY);
		break;
	case DOWN_BREAD:
		down_bread.render(renderer, posX, posY);
		break;
	default:
		break;
	}
}

// Logic
void Dishes::addIngredient(const int &addDish, const int &addIngredient)
{
	ingredients[addDish][numIngredients[addDish]] = addIngredient;
	numIngredients[addDish]++;
}

int Dishes::removeIngredient(const int &removeDish)
{
	int removeIngredient = ingredients[removeDish][numIngredients[removeDish] - 1];
	ingredients[removeDish][numIngredients[removeDish] - 1] = NOTHING;
	numIngredients[removeDish]--;
	return removeIngredient;
}

int Dishes::checkBurger(const int &currentDish)
{
	for (int i = 0; i < NUM_CUSTOMERS; i++)
	{
		int num = customer[i].getNumRequests();
		if (num != numIngredients[currentDish])
			continue;
		int *list = customer[i].getRequestList();
		bool done = true;
		for (int j = 0; j < num; j++)
		{
			if (list[j] != ingredients[currentDish][j])
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