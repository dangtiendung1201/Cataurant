#ifndef _ULTILS_H
#define _ULTILS_H

// C++ libraries
#include <string>
#include <stdlib.h>
#include <fstream>
#include <ostream>
// My libraries
#include "game.h"
#include "texture.h"
#include "const.h"

extern int score;
extern int level;
extern int live;
extern int highestScore;

int random(const int &min, const int &max);

void showScore(SDL_Renderer *renderer);

void readHighestScore();
void updateHighestScore();
void showHighestScore(SDL_Renderer *renderer);

#endif