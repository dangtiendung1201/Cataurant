#include "seller.h"

Seller::Seller()
{
    posX = SELLER_STARTX;
    posY = SELLER_STARTY;
    position = SELLER_START_POSITION;
    status = IDLE;
}

void Seller::loadTexture(SDL_Renderer *renderer)
{
    goRight.loadFromFile(renderer, "assets/images/seller/sellerRight.png");
    goLeft.loadFromFile(renderer, "assets/images/seller/sellerLeft.png");
    stand.loadFromFile(renderer, "assets/images/seller/sellerStand.png");
}

int random(int min, int max)
{
    return min + rand() % (max - min + 1);
}

void Seller::init()
{
    for (int i = 0; i < SELLER_MAXINGREDIENTS; i++)
    {
        ingredients[i] = random(2, 5);
        std::cout << ingredients[i] << " ";
    }
}

void Seller::addTopIngredient()
{
    ingredients[SELLER_MAXINGREDIENTS - 1] = random(2, 5);
}

void Seller::addBottomIngredient(int addIngredient)
{
    for (int i = SELLER_MAXINGREDIENTS - 1; i > 0; i--)
    {
        ingredients[i] = ingredients[i - 1];
    }
    ingredients[0] = addIngredient;
}

int Seller::removeBottomIngredient()
{
    int removeIngredient = ingredients[0];
    for (int i = 0; i < SELLER_MAXINGREDIENTS; i++)
    {
        ingredients[i] = ingredients[i + 1];
    }
    return removeIngredient;
}

void Seller::renderIngredients(SDL_Renderer *renderer, int posX, int posY, int type)
{
    switch (type)
    {
    case UP_BREAD:
        up_bread.render(renderer, posX, posY);
        break;
    case LETTUCE:
        lettuce.render(renderer, posX, posY);
        break;
    case BEEF:
        beef.render(renderer, posX, posY);
        break;
    case TOMATO:
        tomato.render(renderer, posX, posY);
        break;
    case DOWN_BREAD:
        down_bread.render(renderer, posX, posY);
        break;
    default:
        break;
    }
}

void Seller::renderDeque(SDL_Renderer *renderer)
{
    for (int i = 0; i < SELLER_MAXINGREDIENTS_RENDER; i++)
    {
        renderIngredients(renderer, INGREDIENTS_STARTX[position], INGREDIENTS_STARTY - INGREDIENTS_DISTANCE * i, ingredients[i]);
    }
}

int Seller::getDishPosition()
{
    if (position == 2)
        return 0;
    if (position == 3)
        return 1;
    if (position == 4)
        return 2;
    if (position == 5)
        return 3;
    if (position == 6)
        return 4;
}

void Seller::move(SDL_Renderer *renderer)
{
    switch (status)
    {
    case GO_UP:
        if (2 <= position && position <= 6 && dish.getNumIngredients(getDishPosition()) > 1)
            addBottomIngredient(dish.removeIngredient(getDishPosition()));
        break;
    case GO_DOWN:
        if (2 <= position && position <= 6)
        {
            dish.addIngredient(getDishPosition(), removeBottomIngredient());
            addTopIngredient();
        }
        break;
    case GO_LEFT:
        if (posX - SELLER_VEL > 0)
        {
            posX -= SELLER_VEL;
            position--;
            // for (int i = 0; i < SELLER_MAXINGREDIENTS; i++)
            // {
            //     ingredients[i].setX(ingredients[i].getX() - SELLER_VEL);
            // }
        }
        break;
    case GO_RIGHT:
        if (posX + SELLER_VEL < SCREEN_WIDTH - goRight.getWidth() / 4)
        {
            posX += SELLER_VEL;
            position++;
            // for (int i = 0; i < SELLER_MAXINGREDIENTS; i++)
            // {
            //     ingredients[i].setX(ingredients[i].getX() + SELLER_VEL);
            // }
        }
        break;
    }
}

void Seller::handleEvent(SDL_Renderer *renderer, SDL_Event &event)
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
        move(renderer);
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

// void Seller::renderIngredients(SDL_Renderer *renderer)
// {
//     for (int i = 0; i < SELLER_MAXINGREDIENTS_RENDER; i++)
//     {
//         ingredients[i].render(renderer);
//     }
// }

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