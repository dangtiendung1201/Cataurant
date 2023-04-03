#ifndef _CUSTOMER_H
#define _CUSTOMER_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "const.h"
#include "texture.h"

const int MAX_RECT = 9;
const int MAX_REQUEST = 10;

class Customer
{
public:
    Customer();

    void loadTexture(SDL_Renderer *renderer, int type);

    void setMotion();

    void renderBar(SDL_Renderer *renderer);

    void render(SDL_Renderer *renderer, int position);

    void renderRequest(SDL_Renderer *renderer);
    

private:
    int posX, posY, cur, status, type, waitingTime;
    Texture texture;
    SDL_Rect request, rect[MAX_RECT];
    // Ingredients requestList[MAX_REQUEST];
};
#endif
