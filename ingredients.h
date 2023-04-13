#ifndef _INGREDIENTS_H
#define _INGREDIENTS_H

// My libraries
#include "const.h"
#include "texture.h"

class Ingredients
{
public:
	// Constructor and destructor
	Ingredients();
	~Ingredients();

	// Load
	void loadTexture(SDL_Renderer *renderer);

	// Get
	int getType();

	// Set
	void setType(const int &type);

	// Render
	void render(SDL_Renderer *renderer, const int &posX, const int &posY, const int &reduceSize = 1);

private:
	int type;
	Texture texture;
};

extern Ingredients up_bread, lettuce, beef, tomato, down_bread;

#endif