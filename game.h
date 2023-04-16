#ifndef _GAME_H
#define _GAME_H

// C++ libraries
#include <iostream>
#include <vector>
#include <ctime>
// SDL libraries
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
// My libraries
#include "button.h"
#include "const.h"
#include "texture.h"
#include "seller.h"
#include "customer.h"
#include "dishes.h"
#include "ingredients.h"
#include "hungrycat.h"
#include "ultils.h"

extern int gameState;
extern TTF_Font *scoreFont, *highestScoreFont;

bool init();

void load();

void manageState();

void quit();

#endif