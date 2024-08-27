#ifndef _CUSTOMER_H
#define _CUSTOMER_H

// My libraries
#include "ingredients.h"
#include "ultils.h"

class Customer
{
public:
	// Constructor and destructor
	Customer();
	~Customer();

	// Init and reset
	void init();
	void reset();

	void getRequest();

	// Get
	int getNumRequests();
	int *getRequestList();
	
	int getStatus();

	// Set
	void setStatus(const int &status);

	// Logic
	void processOutbound();
	void processRunning(SDL_Renderer *renderer, const int &position);
	void processWaiting(SDL_Renderer *renderer, const int &position);
	void processLeaving(SDL_Renderer *renderer);

	// Render
	void render(SDL_Renderer *renderer, const int &position);

	void renderBar(SDL_Renderer *renderer);
	void renderRequest(SDL_Renderer *renderer, const int &position);
	void renderCharacter(SDL_Renderer *renderer);

private:
	int posX, posY, cur, status, type, request[CUSTOMER_MAXREQUESTS], numRequests;
	float waitingTime;
	Ingredients ingredients;
};

#endif
