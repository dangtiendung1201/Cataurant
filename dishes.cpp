#include "dishes.h"

Dishes::Dishes()
{
    for (int i = 0; i < NUM_DISHES; i++)
    {
        numIngredients[i] = 0;
    }
}

void Dishes::init(SDL_Renderer *renderer)
{
    for (int i = 0; i < NUM_DISHES; i++)
    {
        numIngredients[i] = 1;
        ingredients[i][0].setType(UP_BREAD);
        ingredients[i][0].loadTexture(renderer);
        ingredients[i][0].setX(DISHES_POSX[i]);
        ingredients[i][0].setY(DISHES_POSY);
        ingredients[i][0].setWidth(ingredients[i][0].getWidth());
        ingredients[i][0].setHeight(ingredients[i][0].getHeight());
    }
}

void Dishes::render(SDL_Renderer *renderer)
{
    for (int i = 0; i < NUM_DISHES; i++)
    {
        for (int j = 0; j < numIngredients[i]; j++)
        {
            ingredients[i][j].render(renderer);
        }
    }
}

void Dishes::add(SDL_Renderer *renderer, Ingredients addIngredents, int position)
{
    std::cout << numIngredients[position] << std::endl;
    ingredients[position][numIngredients[position]] = addIngredents;
    ingredients[position][numIngredients[position]].loadTexture(renderer);
    ingredients[position][numIngredients[position]].setX(DISHES_POSX[position]);
    ingredients[position][numIngredients[position]].setY(DISHES_POSY - INGREDIENTS_DISTANCE * numIngredients[position]);
    numIngredients[position]++;
    // std::cout << ingredients[position][numIngredients[position]].getX() << std::endl;
    // std::cout << ingredients[position][numIngredients[position]].getY() << std::endl;
    // std::cout << ingredients[position][numIngredients[position]].getType() << std::endl;
    // std::cout << ingredients[position][numIngredients[position]].getWidth() << std::endl;
    // std::cout << ingredients[position][numIngredients[position]].getHeight() << std::endl;
}
