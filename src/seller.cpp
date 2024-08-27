#include "seller.h"

// Constructor and destructor
Seller::Seller()
{
	posX = SELLER_STARTX;
	posY = SELLER_STARTY;
	position = SELLER_START_POSITION;
	status = IDLE;
}
Seller::~Seller()
{
	reset();
}

// Init and reset
void Seller::init()
{
	for (int i = 0; i < SELLER_MAXINGREDIENTS; i++)
	{
		typeIngredients[i] = random(LETTUCE, DOWN_BREAD);
	}
}

void Seller::reset()
{
	for (int i = 0; i < SELLER_MAXINGREDIENTS; i++)
	{
		typeIngredients[i] = NOTHING;
	}
}

// Get
int Seller::getStatus()
{
	return status;
}

int Seller::getPosition()
{
	return position;
}

// Set
void Seller::setStatus(const int &status)
{
	this->status = status;
}

// Render
void Seller::render(SDL_Renderer *renderer)
{
	if (status == GO_LEFT)
	{
		SDL_Rect clip[1];

		clip[0].x = 0;
		clip[0].y = 0;
		clip[0].w = customerLeft.getWidth() / 4 + 50;
		clip[0].h = customerLeft.getHeight() / 2;

		customerLeft.render(renderer, posX, posY, 0, 0, &clip[cur]);
	}
	else if (status == GO_RIGHT)
	{
		SDL_Rect clip[1];

		clip[0].x = 0;
		clip[0].y = 0;
		clip[0].w = customerRight.getWidth() / 4 - 10;
		clip[0].h = customerRight.getHeight() / 2;

		customerRight.render(renderer, posX, posY, 0, 0, &clip[cur]);
	}
	else if (status == GO_UP)
	{
		customerStand.render(renderer, posX, posY, customerStand.getWidth() / 3, customerStand.getHeight() / 3, NULL);
	}
	else if (status == GO_DOWN)
	{
		customerStand.render(renderer, posX, posY, customerStand.getWidth() / 3, customerStand.getHeight() / 3, NULL);
	}
	else if (status == IDLE)
	{
		customerStand.render(renderer, posX, posY, customerStand.getWidth() / 3, customerStand.getHeight() / 3, NULL);
	}
}

void Seller::renderDeque(SDL_Renderer *renderer)
{
	for (int i = 0; i < SELLER_MAXINGREDIENTS_RENDER; i++)
	{
		ingredients.render(renderer, INGREDIENTS_STARTX[position], INGREDIENTS_STARTY - INGREDIENTS_DISTANCE * i, typeIngredients[i]);
	}
}

// Logic
/***
	Args:
		addIngredient (int): ingredient to add to the top of the deque
	Returns:
		double: None
***/
void Seller::addBottomIngredient(const int &addIngredient)
{
	for (int i = SELLER_MAXINGREDIENTS - 1; i > 0; i--)
	{
		typeIngredients[i] = typeIngredients[i - 1];
	}

	typeIngredients[0] = addIngredient;
}

/***
	Args:
		None
	Returns:
		int: ingredient to remove from the bottom of the deque
***/
int Seller::removeBottomIngredient()
{
	int removeIngredient = typeIngredients[0];

	for (int i = 0; i < SELLER_MAXINGREDIENTS; i++)
	{
		typeIngredients[i] = typeIngredients[i + 1];
	}

	return removeIngredient;
}

void Seller::addTopIngredient()
{
	typeIngredients[SELLER_MAXINGREDIENTS - 1] = random(LETTUCE, DOWN_BREAD);
}

void Seller::goRight()
{
	if (posX + SELLER_STEP < SCREEN_WIDTH - customerRight.getWidth() / 4)
	{
		posX += SELLER_STEP;
		position++;
	}
}

void Seller::goLeft()
{
	if (posX - SELLER_STEP > 0)
	{
		posX -= SELLER_STEP;
		position--;
	}
}