#ifndef _RES_H
#define _RES_H

// C++ libraries
#include <vector>
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
#include "ingredients.h"

extern TTF_Font *menuFont,									 // Menu font
	*titleFont, *versionFont, *scoreFont, *highestScoreFont; // Title font

extern Texture title, version; // Title texture

extern Texture background, helpground, musicOn, soundOn, musicOff, soundOff, gameground, stand, loseground, heart; // Background texture

extern Mix_Music *music;																					   // Music
extern Mix_Chunk *clickSound, *leaveSound, *levelSound, *loseSound, *receiveSound, *wasteSound, *warningSound; // Sound

extern const char *menuText[NUM_BUTTONS];// Menu text

extern std::vector<Button> buttons;
extern SDL_Rect musicRect;
extern SDL_Rect soundRect;
extern Button musicButton;
extern Button soundButton;

extern Texture fox, wolf, talkBubble;
extern SDL_Rect customerRect[CUSTOMER_MOTION_RECTANGLE];

extern Texture customerRight, customerLeft, customerStand;

extern Texture up_bread, lettuce, beef, tomato, down_bread;

bool init(SDL_Window *&window, SDL_Renderer *&renderer);

void load(SDL_Renderer *&renderer);

void quit(SDL_Window *&window, SDL_Renderer *&renderer);

#endif