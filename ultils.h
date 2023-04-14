#ifndef _ULTILS_H
#define _ULTILS_H

// C++ libraries
#include <string>
#include <stdlib.h>
// My libraries
#include "game.h"
#include "texture.h"
#include "const.h"

extern int score;

int random(const int &min, const int &max);

void showScore(SDL_Renderer *renderer);

#endif