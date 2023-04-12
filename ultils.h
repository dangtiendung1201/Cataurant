#ifndef _ULTILS_H
#define _ULTILS_H

#include <string>
#include <stdlib.h>
#include "game.h"
#include "texture.h"
#include "const.h"

extern int score;

void showScore(SDL_Renderer *renderer);

int random(int min, int max);

#endif