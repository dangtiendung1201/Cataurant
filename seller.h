#ifndef _SELLER_H
#define _SELLER_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "const.h"
#include "texture.h"

class Seller
{
public:
    Seller();

    void loadTexture(SDL_Renderer *renderer);

    void handleEvent(SDL_Event &event);

    void move();

    void render(SDL_Renderer *renderer);

    int getPosX();

    int getPosY();

private:
    int posX, posY;
    int status;
    Texture texture;
};
#endif
