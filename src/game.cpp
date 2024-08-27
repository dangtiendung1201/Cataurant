#include "game.h"

Game::Game()
{
	gameState = MENU;
}

Game::~Game()
{
	gameState = QUIT;
}

void Game::setGameState(const int &state)
{
	gameState = state;
}

int Game::getGameState()
{
	return gameState;
}

void Game::gameReset()
{
	score = 0;

	level = MIN_LEVEL;

	live = START_LIVE;

	seller.reset();
	seller.init();

	for (int i = 0; i < NUM_DISHES; i++)
	{
		dish.reset(i);
	}
	dish.init();

	for (int i = 0; i < NUM_CUSTOMERS; i++)
	{
		customer[i].reset();
		customer[i].init();
	}
}

void Game::processUpKey()
{
	int sellerPosition = seller.getPosition();
	int dishPosition = sellerPosition - 2;

	if (SELLER_LEFT_BOUND <= sellerPosition && sellerPosition <= SELLER_RIGHT_BOUND && dish.getNumIngredients(dishPosition) > 1)
		seller.addBottomIngredient(dish.removeIngredient(dishPosition));
}

void Game::processDownKey()
{
	int sellerPosition = seller.getPosition();
	int dishPosition = sellerPosition - 2;

	if (sellerPosition == HUNGRYCAT_POSITION)
	{
		if (hungrycat.getEating() == false)
		{
			Mix_PlayChannel(-1, receiveSound, 0);

			hungrycat.setType(seller.removeBottomIngredient());
			hungrycat.setEating(HUNGRYCAT_EATING_TIME[level]);

			seller.addTopIngredient();
		}
	}
	else if (DISHES_FIRST_POSITION <= sellerPosition && sellerPosition <= DISHES_LAST_POSITION && dish.getNumIngredients(dishPosition) < DISHES_MAX_INGREDIENTS)
	{
		if (dish.getNumIngredients(dishPosition) <= DISHES_LIMIT_INGREDIENTS)
		{
			dish.addIngredient(dishPosition, seller.removeBottomIngredient());
			seller.addTopIngredient();

			if (dish.checkBurger(customer, dishPosition) >= 0)
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
}

void Game::handlePlayEvent(SDL_Renderer *renderer, SDL_Event &event)
{
	// Print event type
	if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
	{
		std::cout << "Key press detected: " << event.key.keysym.sym << std::endl;
		switch (event.key.keysym.sym)
		{
		case SDLK_UP:
			seller.setStatus(GO_UP);

			processUpKey();
			break;
		case SDLK_DOWN:
			seller.setStatus(GO_DOWN);

			processDownKey();
			break;
		case SDLK_LEFT:
			seller.setStatus(GO_LEFT);

			seller.goLeft();
			break;
		case SDLK_RIGHT:
			seller.setStatus(GO_RIGHT);

			seller.goRight();
			break;
		}
	}
	else if (event.type == SDL_KEYUP)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_UP:
			seller.setStatus(IDLE);
			break;
		case SDLK_DOWN:
			seller.setStatus(IDLE);
			break;
		case SDLK_LEFT:
			seller.setStatus(IDLE);
			break;
		case SDLK_RIGHT:
			seller.setStatus(IDLE);
			break;
		}
	}
}

void Game::playBroswer(SDL_Renderer *renderer, SDL_Event &event)
{
	// Handle events
	while (SDL_PollEvent(&event) != 0)
	{
		switch (event.type)
		{
		case SDL_QUIT:
			gameState = QUIT;
			break;
		}

		handlePlayEvent(renderer, event);
	}

	// Clear screen
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);

	// Content
	gameground.render(renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);

	seller.render(renderer);

	stand.render(renderer, SCREEN_WIDTH / 2 - stand.getWidth() / 2, SCREEN_HEIGHT / 2 - stand.getHeight() / 2, stand.getWidth(), stand.getHeight(), NULL);

	for (int i = 0; i < NUM_CUSTOMERS; i++)
	{
		customer[i].render(renderer, i);
	}

	seller.renderDeque(renderer);

	dish.render(renderer);

	showScore(renderer);
	showLive(renderer);

	if (hungrycat.getEating() == true)
	{
		hungrycat.eat(renderer, 1.0 * HUNGRYCAT_START_POSX, 1.0 * HUNGRYCAT_START_POSY, 1.0 * HUNGRYCAT_END_POSX, 1.0 * HUNGRYCAT_END_POSY);
	}

	// Update screen
	SDL_RenderPresent(renderer);
}

void Game::play(SDL_Renderer *renderer)
{
	Uint32 frameStart, frameTime;

	gameReset();

	SDL_Event event;
	bool quit = false;
	while (!quit)
	{
		frameStart = SDL_GetTicks();

		// Handle events on queue
		while (SDL_PollEvent(&event) != 0)
		{
			switch (event.type)
			{
			case SDL_QUIT:
				gameState = QUIT;
				break;
			}

			handlePlayEvent(renderer, event);
		}

		// Clear screen
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer);

		// Render
		gameground.render(renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);

		seller.render(renderer);

		stand.render(renderer, SCREEN_WIDTH / 2 - stand.getWidth() / 2, SCREEN_HEIGHT / 2 - stand.getHeight() / 2, stand.getWidth(), stand.getHeight(), NULL);

		for (int i = 0; i < NUM_CUSTOMERS; i++)
		{
			customer[i].render(renderer, i);
		}

		seller.renderDeque(renderer);

		dish.render(renderer);

		showScore(renderer);
		showLive(renderer);

		if (hungrycat.getEating() == true)
		{
			hungrycat.eat(renderer, 1.0 * HUNGRYCAT_START_POSX, 1.0 * HUNGRYCAT_START_POSY, 1.0 * HUNGRYCAT_END_POSX, 1.0 * HUNGRYCAT_END_POSY);
		}

		// Update screen
		SDL_RenderPresent(renderer);

		// Frame rate
		frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < DELAY_TIME)
		{
			SDL_Delay(DELAY_TIME - frameTime);
		}

		// Change state
		if (live == 0)
		{
			gameState = LOSE;

			Mix_PlayChannel(-1, loseSound, 0);
		}

		// Quit
		if (gameState != PLAY)
			quit = true;
	}
}

void Game::menuReset()
{
	if (musicState)
		Mix_PlayMusic(music, -1);

	if (soundState)
		Mix_Resume(-1);
}

void Game::menu(SDL_Renderer *renderer)
{
	std::cout << "menu" << std::endl;
	Uint32 frameStart, frameTime;

	menuReset();

	SDL_Event event;
	bool quit = false;
	while (!quit)
	{
		frameStart = SDL_GetTicks();
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				gameState = QUIT;
				break;
			case SDL_MOUSEMOTION:
				for (int i = 0; i < NUM_BUTTONS; i++)
				{
					if (buttons[i].isMouseInside(event.motion.x, event.motion.y))
					{
						buttons[i].changeColor(GREEN);
					}
					else
					{
						buttons[i].changeColor(PINK);
					}
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				for (int i = 0; i < NUM_BUTTONS; i++)
				{
					if (buttons[i].isMouseInside(event.motion.x, event.motion.y))
					{
						buttons[i].changeColor(ORANGE);
						if (soundState == ON)
							Mix_PlayChannel(-1, clickSound, 0);
					}
				}
				if (musicButton.isMouseInside(event.motion.x, event.motion.y))
				{
					if (Mix_PausedMusic() == 1)
					{
						Mix_ResumeMusic();
						musicState = ON;
					}
					else
					{
						Mix_PauseMusic();
						musicState = OFF;
					}
				}
				if (soundButton.isMouseInside(event.motion.x, event.motion.y))
				{
					if (soundState == ON)
					{
						Mix_Pause(-1);
						soundState = OFF;
					}
					else
					{
						Mix_Resume(-1);
						soundState = ON;
					}
				}
				break;
			case SDL_MOUSEBUTTONUP:
				for (int i = 0; i < NUM_BUTTONS; i++)
				{
					if (buttons[i].isMouseInside(event.motion.x, event.motion.y))
					{
						buttons[i].changeColor(GREEN);
						switch (i)
						{
						case 0:
							gameState = PLAY;
							break;
						case 1:
							gameState = HELP;
							break;
						case 2:
							gameState = QUIT;
							break;
						}
					}
					else
					{
						buttons[i].changeColor(PINK);
					}
				}
				break;
			}
		}

		// Clear screen
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer);

		// Render
		background.render(renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);

		if (musicState == ON)
			musicOn.render(renderer, MUSIC_POSX, MUSIC_POSY, MUSIC_WIDTH, MUSIC_HEIGHT, NULL);
		else
			musicOff.render(renderer, MUSIC_POSX, MUSIC_POSY, MUSIC_WIDTH, MUSIC_HEIGHT, NULL);

		if (soundState == ON)
			soundOn.render(renderer, SOUND_POSX, SOUND_POSY, SOUND_WIDTH, SOUND_HEIGHT, NULL);
		else
			soundOff.render(renderer, SOUND_POSX, SOUND_POSY, SOUND_WIDTH, SOUND_HEIGHT, NULL);

		title.render(renderer, SCREEN_WIDTH / 2 - title.getWidth() / 2, SCREEN_HEIGHT / 2 - title.getHeight() / 2 - 200, title.getWidth(), title.getHeight(), NULL);

		version.render(renderer, SCREEN_WIDTH - version.getWidth() - 10, 10, version.getWidth(), version.getHeight(), NULL);

		for (int i = 0; i < NUM_BUTTONS; i++)
		{
			buttons[i].render(renderer);
		}

		// Update screen
		SDL_RenderPresent(renderer);

		// Frame rate
		frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < DELAY_TIME)
		{
			SDL_Delay(DELAY_TIME - frameTime);
		}

		// Quit
		if (gameState != MENU)
			quit = true;
	}
}

void Game::help(SDL_Renderer *renderer)
{
	Uint32 frameStart, frameTime;

	SDL_Event event;
	bool quit = false;
	while (!quit)
	{
		frameStart = SDL_GetTicks();

		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				gameState = QUIT;
				break;
			}
			if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					gameState = MENU;
					break;
				case SDLK_SPACE:
					gameState = PLAY;
					break;
				}
			}
		}

		// Clear screen
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer);

		// Render
		helpground.render(renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);

		// Update screen
		SDL_RenderPresent(renderer);

		// Frame rate
		frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < DELAY_TIME)
		{
			SDL_Delay(DELAY_TIME - frameTime);
		}

		// Quit
		if (gameState != HELP)
			quit = true;
	}
}

void Game::lose(SDL_Renderer *renderer)
{
	Uint32 frameStart, frameTime;

	updateHighestScore();
	readHighestScore();

	Mix_HaltMusic();

	SDL_Event event;
	bool quit = false;
	while (!quit)
	{
		frameStart = SDL_GetTicks();

		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				gameState = QUIT;
				break;
			}
			if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					gameState = QUIT;
				case SDLK_SPACE:
					gameState = MENU;
					break;
				}
			}
		}

		// Clear screen
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer);

		// Render
		loseground.render(renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
		showHighestScore(renderer);

		// Update screen
		SDL_RenderPresent(renderer);

		// Frame rate
		frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < DELAY_TIME)
		{
			SDL_Delay(DELAY_TIME - frameTime);
		}

		// Quit
		if (gameState != LOSE)
			quit = true;
	}
}

// manage all states of the game
void Game::manageState(SDL_Renderer *renderer)
{
	while (loop)
	{
		switch (gameState)
		{
		case MENU:
			menu(renderer);
			break;
		case HELP:
			help(renderer);
			break;
		case PLAY:
			play(renderer);
			break;
		case LOSE:
			lose(renderer);
			break;
		case QUIT:
			loop = false;
			break;
		}
	}
}