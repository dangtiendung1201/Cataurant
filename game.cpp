#include "game.h"

SDL_Window *window;
SDL_Renderer *renderer;

bool init()
{
	bool success = true;
	// Initialise SDL video subsystem
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "SDL could not initialise! Error: " << SDL_GetError() << std::endl;
		success = false;
	}

	// Intialise SDL_ttf
	if (TTF_Init() == -1)
	{
		std::cout << "SDL_ttf could not initialise! Error: " << TTF_GetError() << std::endl;
		success = false;
	}

	// Create window
	window = SDL_CreateWindow("Cataurant", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		std::cout << "SDL could not create window! Error: " << SDL_GetError() << std::endl;
		success = false;
	}

	// Create renderer
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer == nullptr)
	{
		std::cout << "SDL could not create renderer! Error: " << SDL_GetError() << std::endl;
		success = false;
	}
	return success;
}
void menu()
{
	// Load fonts
	TTF_Font *menuFont = TTF_OpenFont("assets/fonts/menu.ttf", MENU_SIZE);
	if (menuFont == nullptr)
	{
		std::cout << "Failed to load font! Error: " << TTF_GetError() << std::endl;
	}
	TTF_Font *textFont = TTF_OpenFont("assets/fonts/title.ttf", TITLE_SIZE);
	if (textFont == nullptr)
	{
		std::cout << "Failed to load font! Error: " << TTF_GetError() << std::endl;
	}
	Texture title;
	title.loadFromRenderedText(renderer, "Cataurant", ORANGE, textFont);
	const char *menuText[3] = {"Play", "Options", "Credits"};
	std::vector<Button> buttons;

	for (int i = 0; i < 3; i++)
	{
		SDL_Rect rect = {SCREEN_WIDTH / 2 - BUTTON_WIDTH / 2, SCREEN_HEIGHT / 2 - BUTTON_HEIGHT / 2 + i * (BUTTON_HEIGHT + 50), BUTTON_WIDTH, BUTTON_HEIGHT};
		Button button(rect, PINK, menuFont, ORANGE);
		button.loadTexture(renderer, menuText[i]);
		buttons.push_back(button);
	}

	SDL_Event event;
	bool quit = false;
	while (!quit)
	{
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_MOUSEMOTION:
				for (int i = 0; i < 3; i++)
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
				for (int i = 0; i < 3; i++)
				{
					if (buttons[i].isMouseInside(event.motion.x, event.motion.y))
					{
						buttons[i].changeColor(WHITE);
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
		title.render(renderer, SCREEN_WIDTH / 2 - title.getWidth() / 2, SCREEN_HEIGHT / 2 - title.getHeight() / 2 - 200);
		for (int i = 0; i < 3; i++)
		{
			buttons[i].render(renderer);
		}

		SDL_RenderPresent(renderer);
	}
}