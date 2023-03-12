#include "game.h"

bool init()
{
    bool success = true;
    // Initialise SDL video subsystem
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "SDL could not initialise! Error: " << SDL_GetError() << std::endl;
        success = false;
    }

    // Intialise SDL_ttf
    if (TTF_Init() == -1)
    {
        std::cout << "SDL_ttf could not initialise! Error: " << TTF_GetError() << std::endl;
        success = false;
    }

    // Create window
    SDL_Window *window = SDL_CreateWindow("Cataurant", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
        std::cout << "SDL could not create window! Error: " << SDL_GetError() << std::endl;
        success = false;
    }

    // Create renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == nullptr)
    {
        std::cout << "SDL could not create renderer! Error: " << SDL_GetError() << std::endl;
        success = false;
    }
    return success;
}