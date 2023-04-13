#include "ingredients.h"

// Constructor and destructor
Ingredients::Ingredients()
{
	type = NOTHING;
}

Ingredients::~Ingredients()
{
	texture.free();
}

// Load
void Ingredients::loadTexture(SDL_Renderer *renderer)
{
	switch (type)
	{
	case UP_BREAD:
		texture.loadFromFile(renderer, "assets/images/ingredients/up_bread.png");
		break;
	case LETTUCE:
		texture.loadFromFile(renderer, "assets/images/ingredients/lettuce.png");
		break;
	case BEEF:
		texture.loadFromFile(renderer, "assets/images/ingredients/beef.png");
		break;
	case TOMATO:
		texture.loadFromFile(renderer, "assets/images/ingredients/tomato.png");
		break;
	case DOWN_BREAD:
		texture.loadFromFile(renderer, "assets/images/ingredients/down_bread.png");
		break;
	default:
		break;
	}
}

// Get
int Ingredients::getType()
{
	return type;
}

// Set
void Ingredients::setType(const int &type)
{
	this->type = type;
}

// Render
void Ingredients::render(SDL_Renderer *renderer, const int &posX, const int &posY, const int &reduceSize)
{
	texture.render(renderer, posX, posY, texture.getWidth() / reduceSize, texture.getHeight() / reduceSize, NULL);
}
