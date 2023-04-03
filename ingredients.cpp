#include "ingredients.h"
#include "const.h"

Ingredients::Ingredients()
{
    posX = 0;
    posY = 0;
    type = NOTHING;
    width = 0;
    height = 0;
}
// ~Ingredients::Ingredients()
// {
//     free();
// }
void Ingredients::free()
{
    texture.free();
}

void Ingredients::moveDown(int y)
{
    setY(y);
}

void Ingredients::loadTexture(SDL_Renderer *renderer)
{
    switch (type)
    {
    case UP_BREAD:
        texture.loadFromFile(renderer, "assets/images/ingredients/up_bread.png");
        break;
    case LETTUCE:
        texture.loadFromFile(renderer, "assets/images/ingredients/lettuce.png");
        break;
    case BEEF:
        texture.loadFromFile(renderer, "assets/images/ingredients/beef.png");
        break;
    case TOMATO:
        texture.loadFromFile(renderer, "assets/images/ingredients/tomato.png");
        break;
    case DOWN_BREAD:
        texture.loadFromFile(renderer, "assets/images/ingredients/down_bread.png");
        break;
    default:
        break;
    }
}
void Ingredients::render(SDL_Renderer *renderer)
{
    texture.render(renderer, posX, posY, width, height, NULL);
}
void Ingredients::setX(int x)
{
    posX = x;
}
void Ingredients::setY(int y)
{
    posY = y;
}
void Ingredients::setType(int type)
{
    this->type = type;
}
void Ingredients::setWidth(int width)
{
    this->width = width;
}
void Ingredients::setHeight(int height)
{
    this->height = height;
}
int Ingredients::getX()
{
    return posX;
}
int Ingredients::getY()
{
    return posY;
}
int Ingredients::getType()
{
    return type;
}
int Ingredients::getWidth()
{
    return texture.getWidth();
}
int Ingredients::getHeight()
{
    return texture.getHeight();
}

void Ingredients::init()
{
    setType(rand() % 4 + 2);
}