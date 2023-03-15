#ifndef _CONST_H
#define _CONST_H

#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

// Screen size
const int SCREEN_WIDTH = 1366;
const int SCREEN_HEIGHT = 768;

// State
enum State
{
    MENU = 0,
    PLAY = 1,
    HELP = 2,
    QUIT = 3
};

// Menu
const int NUM_BUTTONS = 3; // Number of buttons
const int BUTTON_WIDTH = 150;
const int BUTTON_HEIGHT = 75;
const int MENU_SIZE = 45;

const int TITLE_WIDTH = 500;
const int TITLE_HEIGHT = 100;
const int TITLE_SIZE = 250;

// Color
const SDL_Color WHITE = {255, 255, 255, 255};
const SDL_Color BLACK = {0, 0, 0, 255};
const SDL_Color YELLOW = {255, 255, 0, 255};
const SDL_Color RED = {255, 0, 0, 255};
const SDL_Color GREEN = {0, 255, 0, 255};
const SDL_Color BLUE = {0, 0, 255, 255};
const SDL_Color ORANGE = {255, 165, 0, 255};
const SDL_Color PINK = {255, 192, 203, 255};
const SDL_Color TRANSPARENT = {0, 0, 0, 0};

#endif