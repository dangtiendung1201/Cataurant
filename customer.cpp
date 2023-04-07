#include "customer.h"

// Texture fox, wolf;

Customer::Customer()
{
    posX = CUSTOMER_STARTX;
    posY = CUSTOMER_STARTY;
    cur = 0;
    status = OUTBOUND;
    type = GHOST;
    waitingTime = 0;
    numRequests = 0;
}

void Customer::init()
{
    type = random(1, 2);
    status = RUNNING;
}

// // Render a waitng bar above customer's head and run to 0
void Customer::renderBar(SDL_Renderer *renderer)
{
    SDL_Rect barGreen, barRed;
    if (status == WAITING)
    {
        barGreen.x = posX + 20;
        barGreen.y = posY - 10;
        barGreen.w = waitingTime;
        barGreen.h = CUSTOMER_BAR_HEIGHT;
        barRed.x = barGreen.x + barGreen.w;
        barRed.y = posY - 10;
        barRed.w = CUSTOMER_MAXWAITINGTIME - barGreen.w;
        barRed.h = CUSTOMER_BAR_HEIGHT;
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
        if (type == FOX)
            fox.render(renderer, posX, posY, 0, 0, &customerRect[cur]);
        else if (type == WOLF)
            wolf.render(renderer, posX, posY, 0, 0, &customerRect[cur]);
        if (posX > CUSTOMER_WAITX[position])
        {
            posX -= CUSTOMER_VELOCITY;
            cur++;
            if (cur == CUSTOMER_MOTION_RECTANGLE)
                cur = 0;
        }
        else
            status = WAITING;
    }
    else if (status == WAITING)
    {
        cur = 0;
        if (type == FOX)
            fox.render(renderer, posX, posY, 0, 0, &customerRect[cur]);
        else if (type == WOLF)
            wolf.render(renderer, posX, posY, 0, 0, &customerRect[cur]);
        renderBar(renderer);
        cur = 0;
        if (waitingTime < CUSTOMER_MAXWAITINGTIME)
            waitingTime += 0.01;
        else
            status = LEAVING;
    }
    else if (status == LEAVING)
    {
        if (type == FOX)
            fox.render(renderer, posX, posY, 0, 0, &customerRect[cur]);
        else if (type == WOLF)
            wolf.render(renderer, posX, posY, 0, 0, &customerRect[cur]);
        if (posX > 0)
        {
            posX -= CUSTOMER_VELOCITY;
            cur++;
            if (cur == CUSTOMER_MOTION_RECTANGLE)
                cur = 0;
        }
        else
            status = OUTBOUND;
    }
}
