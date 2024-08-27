#ifndef _ULTILS_H
#define _ULTILS_H

// C++ libraries
#include <string>
#include <stdlib.h>
#include <fstream>
#include <ostream>
// My libraries
#include "texture.h"
#include "const.h"
#include "res.h"

int random(const int &min, const int &max);

void showLive(SDL_Renderer *renderer);

void showScore(SDL_Renderer *renderer);

void readHighestScore();
void updateHighestScore();
void showHighestScore(SDL_Renderer *renderer);

void levelUp();

#endif