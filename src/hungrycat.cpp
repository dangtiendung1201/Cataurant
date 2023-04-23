#include "hungrycat.h"

// Constructor and destructor
Hungrycat::Hungrycat()
{
	eating = false;
	frame = FPS;
}

Hungrycat::~Hungrycat()
{
}

// Set
void Hungrycat::setType(const int &type)
{
	this->type = type;
}

void Hungrycat::setEating()
{
	eating = true;
	frame = FPS;
}

// Get
bool Hungrycat::getEating()
{
	return eating;
}

// Logic
/***
	Args:
		bonus (double): bonus lives
	Returns:
		None
***/
void Hungrycat::applyBonus(const int &bonus)
{
	if (bonus == 0)
		return;

	live = std::min(live + bonus, MAX_LIVE);
}

/***
	Args:
		None
	Returns:
		int: bonus lives
***/
int Hungrycat::randomBonus()
{
	int randomNumber = random(1, 100), bonus = 0;

	if (randomNumber <= 5)
	{
		// 5% chance to get a bonus of 1 lives
		bonus = 1;
	}
	else if (randomNumber <= 8)
	{
		// 3% chance to get a bonus of 2 lives
		bonus = 2;
	}
	else if (randomNumber <= 10)
	{
		// 2% chance to get a bonus of 3 lives
		bonus = 3;
	}

	return bonus;
}

// Render
void Hungrycat::eat(SDL_Renderer *renderer, const float &fromX, const float &fromY, const float &toX, const float &toY)
{
	// Move from fromX, fromY to toX, toY
	float dx = fromX + (toX - fromX) * frame / FPS;
	float dy = fromY + (toY - fromY) * frame / FPS;

	// Render the ingredient
	switch (type)
	{
	case UP_BREAD:
		up_bread.render(renderer, dx, dy);
		break;
	case LETTUCE:
		lettuce.render(renderer, dx, dy);
		break;
	case BEEF:
		beef.render(renderer, dx, dy);
		break;
	case TOMATO:
		tomato.render(renderer, dx, dy);
		break;
	case DOWN_BREAD:
		down_bread.render(renderer, dx, dy);
		break;
	default:
		break;
	}

	frame--;

	if (frame == 0)
	{
		eating = false;

		applyBonus(randomBonus());
	}
}
