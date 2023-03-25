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

enum binaryState
{
    ON = 1,
    OFF = 0
};

enum customerType
{
    FOX = 0,
    WOLF = 1
};

enum customerStatus
{
    RUNNING = 0,
    WAITING = 1,
    SERVED = 2,
    LEAVING = 3
};


// Menu
const int NUM_BUTTONS = 3; // Number of buttons
const int BUTTON_WIDTH = 150;
const int BUTTON_HEIGHT = 75;
const int MENU_SIZE = 45;

const int TITLE_WIDTH = 500;
const int TITLE_HEIGHT = 100;
const int TITLE_SIZE = 250;
const int VERSION_POSX = SCREEN_WIDTH - 10;
const int VERSION_POSY = 10;
const int VERSION_SIZE = 25;
const int VERSION_WIDTH = 100;
const int VERSION_HEIGHT = 50;

const int SOUND_POSX = 10;
const int SOUND_POSY = 10;

const int MUSIC_POSX = 50;
const int MUSIC_POSY = 10;

const int SOUND_WIDTH = 30;
const int SOUND_HEIGHT = 30;

const int MUSIC_WIDTH = 30;
const int MUSIC_HEIGHT = 30;

// Game
const int NUM_DISHES = 5;
const int NUM_INGREDIENTS = 5;
const int SELLER_STARTX = 475;
const int SELLER_STARTY = 350;
const int SELLER_VEL = 125;

const int CUSTOMER_STARTX = 1400;
const int CUSTOMER_STARTY = 625;
const int CUSTOMER_WAITX[] = {350, 550, 750, 950, 1150};
const int CUSTOMER_VELOCITY = 5;


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