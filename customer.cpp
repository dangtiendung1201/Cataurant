#include "customer.h"

const int BAR_WIDTH = 100;
const int BAR_HEIGHT = 10;
const int MAX_WAITING_TIME = 100;

Customer::Customer()
{
    posX = CUSTOMER_STARTX;
    posY = CUSTOMER_STARTY;
    cur = 0;
    status = RUNNING;
    type = 0;
}

void Customer::loadTexture(SDL_Renderer *renderer, int type)
{
    if (type == FOX)
        texture.loadFromFile(renderer, "assets/images/customer/fox.png");
    else if (type == WOLF)
        texture.loadFromFile(renderer, "assets/images/customer/wolf.png");
}

void Customer::setMotion()
{
    for (int i = 0; i < MAX_RECT; i++)
    {
        rect[i].x = i * 152;
        rect[i].y = 0;
        rect[i].w = 134;
        rect[i].h = 134;
    }
}
// Render a waitng bar above customer's head and run to 0
void Customer::renderBar(SDL_Renderer *renderer)
{
    SDL_Rect barGreen, barRed;
    if (status == WAITING)
    {
        barGreen.x = posX + 20;
        barGreen.y = posY - 10;
        barGreen.w = waitingTime;
        barGreen.h = BAR_HEIGHT;
        barRed.x = barGreen.x + barGreen.w;
        barRed.y = posY - 10;
        barRed.w = MAX_WAITING_TIME - barGreen.w;
        barRed.h = BAR_HEIGHT;
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
        SDL_RenderFillRect(renderer, &barGreen);
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
        SDL_RenderFillRect(renderer, &barRed);
    }
}

void Customer::render(SDL_Renderer *renderer, int position)
{
    // renderRequest(renderer);
    if (status == RUNNING)
    {
        texture.render(renderer, posX, posY, 0, 0, &rect[cur]);
        if (posX > CUSTOMER_WAITX[position])
        {
            posX -= CUSTOMER_VELOCITY;
            cur++;
            if (cur == MAX_RECT)
                cur = 0;
        }
        else
            status = WAITING;
    }
    else if (status == WAITING)
    {
        cur = 0;
        texture.render(renderer, posX, posY, 0, 0, &rect[cur]);
        renderBar(renderer);
        cur = 0;
        if (waitingTime < MAX_WAITING_TIME)
            waitingTime++;
        else
            status = LEAVING;
    }
    else if (status == LEAVING)
    {
        texture.render(renderer, posX, posY, 0, 0, &rect[cur]);
        if (posX > 0)
        {
            posX -= CUSTOMER_VELOCITY;
            cur++;
            if (cur == MAX_RECT)
                cur = 0;
        }
        else
            texture.free();
    }
}

std::string makeRequest(int numIngredients)
{
    std::string request = "1";
    for (int i = 0; i < numIngredients; i++)
    {
        int type = rand() % 4;
        switch (type)
        {
        case LETTUCE:
            request += "2";
            break;
        case BEEF:
            request += "2";
            break;
        case TOMATO:
            request += "4";
            break;
        default:
            break;
        }
    }
    request += "5";
    return request;
}

void Customer::renderRequest(SDL_Renderer *renderer)
{
    if (status == WAITING)
    {
        request.w = 60;
        request.h = 80; // Change when more ingredients are added
        request.x = posX + 100;
        request.y = posY - request.h;
        // Render ingredients from request string
        Texture ingredient;
        ingredient.loadFromFile(renderer, "assets/images/ingredients/lettuce.png");
        ingredient.render(renderer, request.x, request.y, 100, 100, NULL);
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
        SDL_RenderFillRect(renderer, &request);
    }
}