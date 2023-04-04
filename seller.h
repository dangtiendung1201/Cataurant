#ifndef _SELLER_H
#define _SELLER_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "const.h"
#include "texture.h"
#include "ingredients.h"
#include "dishes.h"
#include "game.h"

class Seller
{
public:
    Seller();

    void loadTexture(SDL_Renderer *renderer);

    void handleEvent(SDL_Renderer *renderer, SDL_Event &event);

    void move(SDL_Renderer *renderer);

    void render(SDL_Renderer *renderer);

    int getPosX();

    int getPosY();

    void init(SDL_Renderer *renderer);

    void renderIngredients(SDL_Renderer *renderer);
private:
    int posX, posY, cur, position;
    int status;
    Texture goRight, goLeft, stand;
    Ingredients ingredients[SELLER_MAXINGREDIENTS];
};
#endif
