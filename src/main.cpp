#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#include "res.h"
#include "game.h"

SDL_Window *window;
SDL_Renderer *renderer;
Game game;

int score;
int level;
int live;
int highestScore;

// Forward declaration for the main loop function
void main_loop();

int main(int argc, char *argv[])
{
    srand(time(NULL));

    if (init(window, renderer))
        load(renderer);

    game.setGameState(MENU);

#ifdef __EMSCRIPTEN__
    // Use emscripten_set_main_loop to run the main loop in a browser environment
    emscripten_set_main_loop(main_loop, 0, 1);
#else
    // Traditional game loop
    while (game.getGameState() != QUIT)
    {
        main_loop();
    }
#endif

    quit(window, renderer);

#ifdef __EMSCRIPTEN__
    emscripten_cancel_main_loop();
#endif
    return 0;
}

void main_loop()
{
    game.manageState(renderer);

    // // // Render red background
    // SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    // SDL_RenderClear(renderer);

    // // Render green rectangle
    // SDL_Rect rect = {10, 10, 100, 100};
    // SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    // SDL_RenderFillRect(renderer, &rect);

    // // Render blue rectangle
    // SDL_Rect rect2 = {150, 150, 100, 100};
    // SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    // SDL_RenderFillRect(renderer, &rect2);

    // // Render everything
    // SDL_RenderPresent(renderer);

    // // Sleep for 16ms
    // SDL_Delay(16);
}
