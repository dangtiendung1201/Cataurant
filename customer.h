#ifndef _CUSTOMER_H
#define _CUSTOMER_H

#include <iostream>
#include "const.h"
#include "texture.h"
#include "ultils.h"
#include  "ingredients.h"

class Customer
{
public:
	Customer();

	void init();
	void reset();

	void renderBar(SDL_Renderer *renderer);

	void renderIngredients(SDL_Renderer *renderer, int posX, int posY, int type);

	void render(SDL_Renderer *renderer, int position);

	void getRequest();
	void renderRequest(SDL_Renderer *renderer, int position);
	void renderCharacter(SDL_Renderer *renderer);
	
	int getNumRequests();
	int *getRequestList();

	void setStatus(int curStatus);

private:
	int posX, posY, cur, status, type, request[CUSTOMER_MAXREQUESTS], numRequests;
	float waitingTime;
};

extern Texture fox, wolf, talkBubble;
extern SDL_Rect customerRect[CUSTOMER_MOTION_RECTANGLE];
extern Customer customer[NUM_CUSTOMERS];

#endif
