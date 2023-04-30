#ifndef _GAME_H
#define _GAME_H

// C++ libraries
#include <iostream>
#include <vector>
#include <ctime>
// SDL libraries
#if defined(_WIN64) || defined(_WIN32)
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#endif
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
#include "res.h"

extern int gameState;
extern TTF_Font *scoreFont, *highestScoreFont;
extern Texture heart;
extern Mix_Chunk *leaveSound, *levelSound, *loseSound, *receiveSound, *wasteSound, *warningSound;

void manageState(SDL_Renderer *renderer);

#endif