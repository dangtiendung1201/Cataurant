#include "seller.h"

// Constructor and destructor
Seller::Seller()
{
	posX = SELLER_STARTX;
	posY = SELLER_STARTY;
	position = SELLER_START_POSITION;
	status = IDLE;
}
Seller::~Seller()
{
	reset();
}

// Init and reset
void Seller::init()
{
	for (int i = 0; i < SELLER_MAXINGREDIENTS; i++)
	{
		ingredients[i] = random(LETTUCE, DOWN_BREAD);
	}
}

void Seller::reset()
{
	for (int i = 0; i < SELLER_MAXINGREDIENTS; i++)
	{
		ingredients[i] = NOTHING;
	}
}

// Load
void Seller::loadTexture(SDL_Renderer *renderer)
{
	goRight.loadFromFile(renderer, "assets/images/seller/sellerRight.png");
	goLeft.loadFromFile(renderer, "assets/images/seller/sellerLeft.png");
	stand.loadFromFile(renderer, "assets/images/seller/sellerStand.png");
}

// Handle event
void Seller::handleEvent(SDL_Renderer *renderer, SDL_Event &event)
{
	if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_UP:
			status = GO_UP;
			break;
		case SDLK_DOWN:
			status = GO_DOWN;
			break;
		case SDLK_LEFT:
			status = GO_LEFT;
			break;
		case SDLK_RIGHT:
			status = GO_RIGHT;
			break;
		}

		move();
	}
	else if (event.type == SDL_KEYUP)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_UP:
			status = IDLE;
			break;
		case SDLK_DOWN:
			status = IDLE;
			break;
		case SDLK_LEFT:
			status = IDLE;
			break;
		case SDLK_RIGHT:
			status = IDLE;
			break;
		}
	}
}

// Get
int Seller::getDishPosition()
{
	if (position >= 2 && position <= 6)
		return position - 2;
	return 0;
}

// Render
void Seller::render(SDL_Renderer *renderer)
{
	if (status == GO_LEFT)
	{
		SDL_Rect clip[1];

		clip[0].x = 0;
		clip[0].y = 0;
		clip[0].w = goLeft.getWidth() / 4 + 50;
		clip[0].h = goLeft.getHeight() / 2;

		goLeft.render(renderer, posX, posY, 0, 0, &clip[cur]);
	}
	else if (status == GO_RIGHT)
	{
		SDL_Rect clip[1];

		clip[0].x = 0;
		clip[0].y = 0;
		clip[0].w = goRight.getWidth() / 4 - 10;
		clip[0].h = goRight.getHeight() / 2;

		goRight.render(renderer, posX, posY, 0, 0, &clip[cur]);
	}
	else if (status == GO_UP)
	{
		stand.render(renderer, posX, posY, stand.getWidth() / 3, stand.getHeight() / 3, NULL);
	}
	else if (status == GO_DOWN)
	{
		stand.render(renderer, posX, posY, stand.getWidth() / 3, stand.getHeight() / 3, NULL);
	}
	else if (status == IDLE)
	{
		stand.render(renderer, posX, posY, stand.getWidth() / 3, stand.getHeight() / 3, NULL);
	}
}

void Seller::renderIngredients(SDL_Renderer *renderer, const int &posX, const int &posY, const int &type)
{
	switch (type)
	{
	case UP_BREAD:
		up_bread.render(renderer, posX, posY);
		break;
	case LETTUCE:
		lettuce.render(renderer, posX, posY);
		break;
	case BEEF:
		beef.render(renderer, posX, posY);
		break;
	case TOMATO:
		tomato.render(renderer, posX, posY);
		break;
	case DOWN_BREAD:
		down_bread.render(renderer, posX, posY);
		break;
	default:
		break;
	}
}

void Seller::renderDeque(SDL_Renderer *renderer)
{
	for (int i = 0; i < SELLER_MAXINGREDIENTS_RENDER; i++)
	{
		renderIngredients(renderer, INGREDIENTS_STARTX[position], INGREDIENTS_STARTY - INGREDIENTS_DISTANCE * i, ingredients[i]);
	}
}

// Logic
/***
	Args:
		addIngredient (int): ingredient to add to the top of the deque
	Returns:
		double: None
***/
void Seller::addBottomIngredient(const int &addIngredient)
{
	for (int i = SELLER_MAXINGREDIENTS - 1; i > 0; i--)
	{
		ingredients[i] = ingredients[i - 1];
	}

	ingredients[0] = addIngredient;
}

/***
	Args:
		None
	Returns:
		int: ingredient to remove from the bottom of the deque
***/
int Seller::removeBottomIngredient()
{
	int removeIngredient = ingredients[0];

	for (int i = 0; i < SELLER_MAXINGREDIENTS; i++)
	{
		ingredients[i] = ingredients[i + 1];
	}

	return removeIngredient;
}

void Seller::addTopIngredient()
{
	ingredients[SELLER_MAXINGREDIENTS - 1] = random(LETTUCE, DOWN_BREAD);
}

void Seller::move()
{
	switch (status)
	{
	case GO_UP:
		if (2 <= position && position <= 6 && dish.getNumIngredients(getDishPosition()) > 1)
			addBottomIngredient(dish.removeIngredient(getDishPosition()));
		break;
	case GO_DOWN:
		if (position == 0)
		{
			if (hungrycat.getEating() == false)
			{
				Mix_PlayChannel(-1, receiveSound, 0);

				hungrycat.setType(removeBottomIngredient());
				hungrycat.setEating();

				addTopIngredient();
			}
		}
		else if (DISHES_FIRST_POSITION <= position && position <= DISHES_LAST_POSITION && dish.getNumIngredients(getDishPosition()) < DISHES_MAX_INGREDIENTS)
		{
			int dishPosition = getDishPosition();

			if (dish.getNumIngredients(dishPosition) <= DISHES_LIMIT_INGREDIENTS)
			{
				dish.addIngredient(getDishPosition(), removeBottomIngredient());
				addTopIngredient();

				if (dish.checkBurger(getDishPosition()) >= 0)
				{
					score++;

					Mix_PlayChannel(-1, receiveSound, 0);
					
					levelUp();
				}
			}
			else
				Mix_PlayChannel(-1, warningSound, 0);
		}
		else
			Mix_PlayChannel(-1, wasteSound, 0);
		break;
	case GO_LEFT:
		if (posX - SELLER_STEP > 0)
		{
			posX -= SELLER_STEP;
			position--;
		}
		break;
	case GO_RIGHT:
		if (posX + SELLER_STEP < SCREEN_WIDTH - goRight.getWidth() / 4)
		{
			posX += SELLER_STEP;
			position++;
		}
		break;
	}
}