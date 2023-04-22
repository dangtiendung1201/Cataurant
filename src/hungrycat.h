#ifndef _HUNGRYCAT_H
#define _HUNGRYCAT_H

// My libraries
#include "ingredients.h"
#include "const.h"
#include "ultils.h"

struct Hungrycat
{
public:
	// Constructor and destructor
	Hungrycat();
	~Hungrycat();

	// Set
	void setType(const int &type);
	void setEating();

	// Get
	bool getEating();

	// Logic
	void applyBonus(const int &bonus);
	int randomBonus();

	// Render
	void eat(SDL_Renderer *renderer, const float &fromX, const float &fromY, const float &toX, const float &toY);

private:
	bool eating;
	int type, frame;
};
extern Hungrycat hungrycat;
#endif