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

    void render(SDL_Renderer *renderer, int posX, int posY);
    void loadTexture(SDL_Renderer *renderer);
    void free();

    void setType(int type);

    int getType();

private:
    int type;
    Texture texture;
};

extern Ingredients up_bread, lettuce, beef, tomato, down_bread;

#endif