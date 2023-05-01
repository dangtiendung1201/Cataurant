#include "ingredients.h"

// Constructor and destructor
Ingredients::Ingredients()
{
}

Ingredients::~Ingredients()
{
}

// Render
void Ingredients::render(SDL_Renderer *renderer, const int &posX, const int &posY, const int &type, const int &reduceSize)
{
	// texture.render(renderer, posX, posY, texture.getWidth() / reduceSize, texture.getHeight() / reduceSize, NULL);
	switch (type)
	{
	case UP_BREAD:
		up_bread.render(renderer, posX, posY, up_bread.getWidth() / reduceSize, up_bread.getHeight() / reduceSize, NULL);
		break;
	case LETTUCE:
		lettuce.render(renderer, posX, posY, lettuce.getWidth() / reduceSize, lettuce.getHeight() / reduceSize, NULL);
		break;
	case BEEF:
		beef.render(renderer, posX, posY, beef.getWidth() / reduceSize, beef.getHeight() / reduceSize, NULL);
		break;
	case TOMATO:
		tomato.render(renderer, posX, posY, tomato.getWidth() / reduceSize, tomato.getHeight() / reduceSize, NULL);
		break;
	case DOWN_BREAD:
		down_bread.render(renderer, posX, posY, down_bread.getWidth() / reduceSize, down_bread.getHeight() / reduceSize, NULL);
		break;
	}
}
