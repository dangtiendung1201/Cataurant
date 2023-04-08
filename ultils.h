#ifndef _ULTILS_H
#define _ULTILS_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include "texture.h"
#include "game.h"
#include "const.h"

extern int score;

void showScore(SDL_Renderer *renderer);

int random(int min, int max);

#endif