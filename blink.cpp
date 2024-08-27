#include <SDL.h>
#include <emscripten.h>
#include <iostream>


const int SCREEN_WIDTH = 1366;
const int SCREEN_HEIGHT = 768;
const int SQUARE_SIZE = 100;

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
bool showSquare = true;
Uint32 lastTime = 0;
const Uint32 BLINK_INTERVAL = 1000; // 1 second

void drawSquare(bool show) {
    if (show) {
        // Set the drawing color to red
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        // Create a rectangle representing the square
        SDL_Rect square = { (SCREEN_WIDTH - SQUARE_SIZE) / 2, (SCREEN_HEIGHT - SQUARE_SIZE) / 2, SQUARE_SIZE, SQUARE_SIZE };
        // Render the square
        SDL_RenderFillRect(renderer, &square);
    } else {
        // Clear the screen to black (or any other background color)
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
    }
    // Update the screen
    SDL_RenderPresent(renderer);
}

void mainLoop() {
    Uint32 currentTime = SDL_GetTicks();

    // Check if it's time to toggle the square's visibility
    if (currentTime - lastTime >= BLINK_INTERVAL) {
        showSquare = !showSquare;
        lastTime = currentTime;
    }

    // Draw the square (or clear the screen)
    drawSquare(showSquare);

    // Handle events
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            emscripten_cancel_main_loop(); // Stop the main loop in the browser
        }
    }
}

int main(int argc, char* args[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create a window
    window = SDL_CreateWindow("Blinking Square", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create a renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    lastTime = SDL_GetTicks();

    // Set the main loop function for Emscripten
    emscripten_set_main_loop(mainLoop, 0, 1);

    // SDL cleanup will not be reached since emscripten_set_main_loop doesn't return
    return 0;
}
