#include "seller.h"

Seller::Seller()
{
    posX = SELLER_STARTX;
    posY = SELLER_STARTY;
    status = 0;
}
void Seller::loadTexture(SDL_Renderer *renderer)
{
    texture.loadFromFile(renderer, "assets/images/seller.png");
}
void Seller::move()
{
    switch (status)
    {
    case 1:
        
        break;
    case 2:
        
        break;
    case 3:
        posX -= SELLER_VEL;
        break;
    case 4:
        posX += SELLER_VEL;
        break;
    }
}

void Seller::handleEvent(SDL_Event &event)
{
    if (event.type == SDL_KEYDOWN)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_UP:
            status = 1;
            break;
        case SDLK_DOWN:
            status = 2;
            break;
        case SDLK_LEFT:
            status = 3;
            break;
        case SDLK_RIGHT:
            status = 4;
            break;
        }
    }
    else if (event.type == SDL_KEYUP)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_UP:
            status = 0;
            break;
        case SDLK_DOWN:
            status = 0;
            break;
        case SDLK_LEFT:
            status = 0;
            break;
        case SDLK_RIGHT:
            status = 0;
            break;
        }
    }
    move();
}

void Seller::render(SDL_Renderer *renderer)
{
    texture.render(renderer, posX, posY, texture.getWidth() / 3, texture.getHeight() / 3);
}