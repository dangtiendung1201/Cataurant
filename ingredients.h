#ifndef _INGREDIENTS_H
#define _INGREDIENTS_H

#include <SDL.h>
#include <SDL_image.h>
#include "const.h"
#include "texture.h"

class Ingredients
{
public:
    Ingredients();
    // ~Ingredients();

    void render(SDL_Renderer *renderer);
    void loadTexture(SDL_Renderer *renderer);
    void free();

    void setX(int x);
    void setY(int y);
    void setType(int type);
    void setWidth(int width);
    void setHeight(int height);

    int getX();
    int getY();
    int getType();
    int getWidth();
    int getHeight();

    void init();
    void moveDown(int y);
    Ingredients &operator=(const Ingredients &other);

private:
    int posX, posY;
    int type;
    int width, height;
    Texture texture;
};

#endif