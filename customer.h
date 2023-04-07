#ifndef _CUSTOMER_H
#define _CUSTOMER_H

#include "const.h"
#include "texture.h"
#include "ultils.h"

class Customer
{
public:
    Customer();

    void init();

    void renderBar(SDL_Renderer *renderer);

    void render(SDL_Renderer *renderer, int position);

    // void renderRequest(SDL_Renderer *renderer);
    

private:
    int posX, posY, cur, status, type, request[CUSTOMER_MAXREQUESTS], numRequests;
    float waitingTime;
};

extern Texture fox, wolf;
extern SDL_Rect customerRect[CUSTOMER_MOTION_RECTANGLE];

#endif
