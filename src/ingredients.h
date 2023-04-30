#ifndef _INGREDIENTS_H
#define _INGREDIENTS_H

// My libraries
#include "const.h"
#include "texture.h"
#include "res.h"

class Ingredients
{
public:
	// Constructor and destructor
	Ingredients();
	~Ingredients();

	// Render
	void render(SDL_Renderer *renderer, const int &posX, const int &posY, const int &type, const int &reduceSize = 1);
};

extern Ingredients ingredients;

#endif