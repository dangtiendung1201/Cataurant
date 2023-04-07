#include "ingredients.h"

Ingredients::Ingredients()
{
    type = NOTHING;
}
// ~Ingredients::Ingredients()
// {
//     free();
// }
void Ingredients::free()
{
    texture.free();
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
void Ingredients::render(SDL_Renderer *renderer, int posX, int posY)
{
    texture.render(renderer, posX, posY, texture.getWidth(), texture.getHeight(), NULL);
}

void Ingredients::setType(int type)
{
    this->type = type;
}

int Ingredients::getType()
{
    return type;
}