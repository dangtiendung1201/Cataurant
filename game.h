#ifndef _GAME_H
#define _GAME_H

#include <iostream>
#include <vector>
#include <ctime>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "button.h"
#include "const.h"
#include "texture.h"
#include "seller.h"
#include "customer.h"
#include "dishes.h"
#include "ingredients.h"

extern Dishes dish;

bool init();

void menu();

void quit();

#endif