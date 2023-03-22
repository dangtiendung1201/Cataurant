#include "seller.h"

Seller::Seller()
{
    posX = SELLER_STARTX;
    posY = SELLER_STARTY;
    status = 0;
}
void Seller::loadTexture(SDL_Renderer *renderer)
{
    goRight.loadFromFile(renderer, "assets/images/seller/sellerRight.png");
    goLeft.loadFromFile(renderer, "assets/images/seller/sellerLeft.png");
    stand.loadFromFile(renderer, "assets/images/seller/sellerStand.png");
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
        if (posX - SELLER_VEL > 0)
            posX -= SELLER_VEL;
        break;
    case 4:
        if (posX + SELLER_VEL < SCREEN_WIDTH - goRight.getWidth() / 4)
            posX += SELLER_VEL;
        break;
    }
}
void Seller::handleEvent(SDL_Event &event)
{
    if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
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
        move();
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
}
void Seller::render(SDL_Renderer *renderer)
{
    if (status == 3)
    {
        SDL_Rect clip[1];
        clip[0].x = 0;
        clip[0].y = 0;
        clip[0].w = goLeft.getWidth() / 4 + 50;
        clip[0].h = goLeft.getHeight() / 2;
        goLeft.render(renderer, posX, posY, 0, 0, &clip[cur]);
    }
    else if (status == 4)
    {
        SDL_Rect clip[1];
        clip[0].x = 0;
        clip[0].y = 0;
        clip[0].w = goRight.getWidth() / 4 - 10;
        clip[0].h = goRight.getHeight() / 2;
        goRight.render(renderer, posX, posY, 0, 0, &clip[cur]);
    }
    else
    {
        stand.render(renderer, posX, posY, stand.getWidth() / 3, stand.getHeight() / 3, NULL);
    }
}