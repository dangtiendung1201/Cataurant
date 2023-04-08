#include "customer.h"

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
	getRequest();
}

void Customer::getRequest()
{
	numRequests = random(3, 10);
	request[0] = UP_BREAD;
	request[numRequests - 1] = DOWN_BREAD;
	for (int i = 1; i < numRequests - 1; i++)
	{
		request[i] = random(2, 4);
	}
	std::cout << std::endl
			  << "Customer request: " << numRequests << " ingredients:";
	for (int i = 0; i < numRequests; i++)
	{
		std::cout << request[i] << " ";
	}
}

void Customer::renderIngredients(SDL_Renderer *renderer, int posX, int posY, int type)
{
	switch (type)
	{
	case UP_BREAD:
		up_bread.render(renderer, posX, posY, 2);
		break;
	case LETTUCE:
		lettuce.render(renderer, posX, posY, 2);
		break;
	case BEEF:
		beef.render(renderer, posX, posY, 2);
		break;
	case TOMATO:
		tomato.render(renderer, posX, posY, 2);
		break;
	case DOWN_BREAD:
		down_bread.render(renderer, posX, posY, 2);
		break;
	default:
		break;
	}
}

void Customer::renderRequest(SDL_Renderer *renderer, int position)
{
	talkBubble.render(renderer, CUSTOMER_BUBBLE_POSX[position], CUSTOMER_BUBBLE_POSY - CUSTOMER_BUBBLE_DISTANCE * numRequests, CUSTOMER_BUBBLE_WIDTH, CUSTOMER_BUBBLE_DISTANCE * numRequests, NULL);

	for (int i = 0; i < numRequests; i++)
	{
		renderIngredients(renderer, CUSTOMER_REQUESTS_POSX[position], CUSTOMER_REQUESTS_POSY - CUSTOMER_REQUESTS_DISTANCE * i, request[i]);
	}
}

void Customer::renderCharacter(SDL_Renderer *renderer)
{
	if (type == FOX)
		fox.render(renderer, posX, posY, 0, 0, &customerRect[cur]);
	else if (type == WOLF)
		wolf.render(renderer, posX, posY, 0, 0, &customerRect[cur]);
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

void Customer::reset()
{
	posX = CUSTOMER_STARTX;
	posY = CUSTOMER_STARTY;
	cur = 0;
	waitingTime = 0;
	numRequests = 0;
}

void Customer::render(SDL_Renderer *renderer, int position)
{
	if (status == OUTBOUND)
	{
		reset();
		init();
	}
	if (status == RUNNING)
	{
		renderCharacter(renderer);
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
		renderRequest(renderer, position);
		cur = 0;
		renderCharacter(renderer);
		renderBar(renderer);
		cur = 0;
		if (waitingTime < CUSTOMER_MAXWAITINGTIME)
			waitingTime += 0.01;
		else
			status = LEAVING;
	}
	else if (status == LEAVING)
	{
		renderCharacter(renderer);
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

int Customer::getNumRequests()
{
	return numRequests;
}

int *Customer::getRequestList()
{
	return request;
}

void Customer::setStatus(int curStatus)
{
	status = curStatus;
}