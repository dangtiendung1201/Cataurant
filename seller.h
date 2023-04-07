#ifndef _SELLER_H
#define _SELLER_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "const.h"
#include "texture.h"
#include "ingredients.h"
#include "dishes.h"
#include "ultils.h"

class Seller
{
public:
    Seller();

    void loadTexture(SDL_Renderer *renderer);

    void handleEvent(SDL_Renderer *renderer, SDL_Event &event);

    void move(SDL_Renderer *renderer);

    void render(SDL_Renderer *renderer);

    void init();

    void renderIngredients(SDL_Renderer *renderer, int posX, int posY, int type);

    void renderDeque(SDL_Renderer *renderer);

    int getDishPosition();

    int removeBottomIngredient();
    void addBottomIngredient(int addIngredient);
    void addTopIngredient();

private:
    int posX, posY, cur, position;
    int status;
    Texture goRight, goLeft, stand;
    int ingredients[SELLER_MAXINGREDIENTS];
};
#endif
