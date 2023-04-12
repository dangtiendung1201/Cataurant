#ifndef _HUNGRYCAT_H
#define _HUNGRYCAT_H

#include <iostream>
#include "ingredients.h"
#include "const.h"

struct Hungrycat
{
public:
    Hungrycat();
    void eat(SDL_Renderer *renderer, float fromX, float fromY, float toX, float toY);
    bool getEating();
    void setEating();
    void setType(int type);
private:
    bool eating;
    int type, frame;
};
extern Hungrycat hungrycat;
#endif