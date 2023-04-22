#include "hungrycat.h"

// Constructor and destructor
Hungrycat::Hungrycat()
{
    eating = false;
    frame = FPS;
}

Hungrycat::~Hungrycat()
{
}

// Set
void Hungrycat::setType(const int &type)
{
    this->type = type;
}

void Hungrycat::setEating()
{
    eating = true;
    frame = FPS;
}

// Get
bool Hungrycat::getEating()
{
    return eating;
}

// Render
void Hungrycat::eat(SDL_Renderer *renderer, const float &fromX, const float &fromY, const float &toX, const float &toY)
{
    // Move from fromX, fromY to toX, toY
    float dx = fromX + (toX - fromX) * frame / FPS;
    float dy = fromY + (toY - fromY) * frame / FPS;
    // Render the ingredient
    switch (type)
    {
    case UP_BREAD:
        up_bread.render(renderer, dx, dy);
        break;
    case LETTUCE:
        lettuce.render(renderer, dx, dy);
        break;
    case BEEF:
        beef.render(renderer, dx, dy);
        break;
    case TOMATO:
        tomato.render(renderer, dx, dy);
        break;
    case DOWN_BREAD:
        down_bread.render(renderer, dx, dy);
        break;
    default:
        break;
    }
    frame--;
    if (frame == 0)
        eating = false;
}
