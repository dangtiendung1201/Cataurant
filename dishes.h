#ifndef _DISHES_H
#define _DISHES_H

#include <iostream>
#include "const.h"
#include "ingredients.h"
#include "texture.h"

class Dishes
{
public:
    Dishes();
    // ~Dishes();

    void init(SDL_Renderer *renderer);
    void render(SDL_Renderer *renderer);
    void add(SDL_Renderer *renderer, Ingredients addIngredents, int position);
    Ingredients remove(SDL_Renderer *renderer, int position);

private:
    int numIngredients[NUM_DISHES], position;
    Ingredients ingredients[NUM_DISHES][DISHES_MAXINGREDIENTS];
};

#endif