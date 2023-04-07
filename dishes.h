#ifndef _DISHES_H
#define _DISHES_H

#include "ingredients.h"
#include "const.h"
#include <string>

class Dishes
{
public:
    Dishes();
    // ~Dishes();

    void loadTexture(SDL_Renderer *renderer);

    void renderIngredients(SDL_Renderer *renderer, int posX, int posY, int type);

    void render(SDL_Renderer *renderer);

    void init();

    void addIngredient(int addDish, int addIngredient);
    int removeIngredient(int removeDish);
    int getNumIngredients(int currentDish);

private:
    int ingredients[NUM_DISHES][DISHES_MAXINGREDIENTS];
    int numIngredients[NUM_DISHES];
};

extern Dishes dish;

#endif