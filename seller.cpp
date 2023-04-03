#include "seller.h"

Seller::Seller()
{
    posX = SELLER_STARTX;
    posY = SELLER_STARTY;
    position = 4;
    status = IDLE;
}

void Seller::loadTexture(SDL_Renderer *renderer)
{
    goRight.loadFromFile(renderer, "assets/images/seller/sellerRight.png");
    goLeft.loadFromFile(renderer, "assets/images/seller/sellerLeft.png");
    stand.loadFromFile(renderer, "assets/images/seller/sellerStand.png");
}

void Seller::init(SDL_Renderer *renderer)
{
    for (int i = 0; i < SELLER_MAXINGREDIENTS; i++)
    {
        ingredients[i].init();
        ingredients[i].loadTexture(renderer);
        ingredients[i].setX(INGREDIENTS_STARTX);
        ingredients[i].setY(INGREDIENTS_STARTY - INGREDIENTS_DISTANCE * i);
        ingredients[i].setWidth(ingredients[i].getWidth());
        ingredients[i].setHeight(ingredients[i].getHeight());
    }
}

void Seller::move()
{
    switch (status)
    {
    case GO_UP:

        break;
    case GO_DOWN:
        ingredients[0].moveDown(400);
        
        break;
    case GO_LEFT:
        if (posX - SELLER_VEL > 0)
        {
            posX -= SELLER_VEL;
            position--;
            for (int i = 0; i < SELLER_MAXINGREDIENTS; i++)
            {
                ingredients[i].setX(ingredients[i].getX() - SELLER_VEL);
            }
        }
        break;
    case GO_RIGHT:
        if (posX + SELLER_VEL < SCREEN_WIDTH - goRight.getWidth() / 4)
        {
            posX += SELLER_VEL;
            for (int i = 0; i < SELLER_MAXINGREDIENTS; i++)
            {
                ingredients[i].setX(ingredients[i].getX() + SELLER_VEL);
            }
        }
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
            status = GO_UP;
            break;
        case SDLK_DOWN:
            status = GO_DOWN;
            break;
        case SDLK_LEFT:
            status = GO_LEFT;
            break;
        case SDLK_RIGHT:
            status = GO_RIGHT;
            break;
        }
        move();
    }
    else if (event.type == SDL_KEYUP)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_UP:
            status = IDLE;
            break;
        case SDLK_DOWN:
            status = IDLE;
            break;
        case SDLK_LEFT:
            status = IDLE;
            break;
        case SDLK_RIGHT:
            status = IDLE;
            break;
        }
    }
}

void Seller::renderIngredients(SDL_Renderer *renderer)
{
    for (int i = 0; i < SELLER_MAXINGREDIENTS; i++)
    {
        ingredients[i].render(renderer);
    }
}

void Seller::render(SDL_Renderer *renderer)
{
    if (status == GO_LEFT)
    {
        SDL_Rect clip[1];
        clip[0].x = 0;
        clip[0].y = 0;
        clip[0].w = goLeft.getWidth() / 4 + 50;
        clip[0].h = goLeft.getHeight() / 2;
        goLeft.render(renderer, posX, posY, 0, 0, &clip[cur]);
    }
    else if (status == GO_RIGHT)
    {
        SDL_Rect clip[1];
        clip[0].x = 0;
        clip[0].y = 0;
        clip[0].w = goRight.getWidth() / 4 - 10;
        clip[0].h = goRight.getHeight() / 2;
        goRight.render(renderer, posX, posY, 0, 0, &clip[cur]);
    }
    else if (status == GO_UP)
    {
        stand.render(renderer, posX, posY, stand.getWidth() / 3, stand.getHeight() / 3, NULL);
    }
    else if (status == GO_DOWN)
    {

        stand.render(renderer, posX, posY, stand.getWidth() / 3, stand.getHeight() / 3, NULL);
    }
    else if (status == IDLE)
    {
        stand.render(renderer, posX, posY, stand.getWidth() / 3, stand.getHeight() / 3, NULL);
    }
    // std::cout << position << std::endl;
}