#include "game.h"

SDL_Window *window;
SDL_Renderer *renderer;

bool init()
{
	// Initialization flag
	bool success = true;

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
		success = false;
	}
	else
	{
		// Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			std::cout << "Warning: Linear texture filtering not enabled!" << std::endl;
		}

		// Create window
		window = SDL_CreateWindow("Caturant", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
			success = false;
		}
		else
		{
			// Create vsynced renderer for window
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (renderer == NULL)
			{
				std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
				success = false;
			}
			else
			{
				// Initialize renderer color
				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

				// Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
					success = false;
				}

				if (TTF_Init() == -1)
				{
					std::cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << std::endl;
					success = false;
				}
			}
		}
	}

	// Initialise SDL_mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		std::cout << "SDL_mixer could not initialise! Error: " << Mix_GetError() << std::endl;
		success = false;
	}
	return success;
}

void loadFont(TTF_Font *&font, const char *path, const int size)
{
	font = TTF_OpenFont(path, size);
	if (font == nullptr)
	{
		std::cout << "Failed to load font! Error: " << TTF_GetError() << std::endl;
	}
}

void loadImage(Texture &texture, const char *path)
{
	if (!texture.loadFromFile(renderer, path))
	{
		std::cout << "Failed to load image! Error: " << SDL_GetError() << std::endl;
	}
}

void loadSound(Mix_Music *&sound, const char *path)
{
	sound = Mix_LoadMUS(path);
	if (sound == nullptr)
	{
		std::cout << "Failed to load sound! Error: " << Mix_GetError() << std::endl;
	}
}

void menu()
{
	// Const
	const int NUM_BUTTONS = 3; // Number of buttons

	// Declearation
	TTF_Font *menuFont, // Menu font
		*titleFont;		// Title font

	Texture title; // Title texture

	Texture background; // Background texture

	Mix_Music *music; // Click sound

	const char *menuText[NUM_BUTTONS] = {"Play", "Options", "Credits"}; // Menu text
	std::vector<Button> buttons;										// Menu buttons

	// Load fonts
	loadFont(menuFont, "assets/fonts/menu.ttf", MENU_SIZE);
	loadFont(titleFont, "assets/fonts/title.ttf", TITLE_SIZE);

	// Load title
	title.loadFromRenderedText(renderer, "Cataurant", ORANGE, titleFont);

	// Load background
	loadImage(background, "assets/images/background.png");

	// Load music
	loadSound(music, "assets/sounds/music.wav");

	// Load buttons
	for (int i = 0; i < NUM_BUTTONS; i++)
	{
		SDL_Rect rect = {SCREEN_WIDTH / 2 - BUTTON_WIDTH / 2, SCREEN_HEIGHT / 2 - BUTTON_HEIGHT / 2 + i * (BUTTON_HEIGHT + 50), BUTTON_WIDTH, BUTTON_HEIGHT};
		Button button(rect, PINK, menuFont, ORANGE);
		button.loadTexture(renderer, menuText[i]);
		// set button position

		buttons.push_back(button);
	}

	// Main loop
	SDL_Event event;
	bool quit = false;
	Mix_PlayMusic(music, -1);
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
							// game();
							std::cout << "Play" << std::endl;
							break;
						case 1:
							// options();
							std::cout << "Options" << std::endl;
							break;
						case 2:
							// credits();
							std::cout << "Credits" << std::endl;
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
		// while (SDL_PollEvent(&event))
		// {
		// 	switch (event.type)
		// 	{
		// 	case SDL_QUIT:
		// 		quit = true;
		// 		break;
		// 	case SDL_MOUSEMOTION:
		// 		for (int i = 0; i < NUM_BUTTONS; i++)
		// 		{
		// 			if (buttons[i].isMouseInside(event.motion.x, event.motion.y))
		// 			{
		// 				buttons[i].changeColor(GREEN);
		// 			}
		// 			else
		// 			{
		// 				buttons[i].changeColor(PINK);
		// 			}
		// 		}
		// 		break;
		// 	case SDL_MOUSEBUTTONDOWN:
		// 		for (int i = 0; i < 3; i++)
		// 		{
		// 			if (buttons[i].isMouseInside(event.motion.x, event.motion.y))
		// 			{
		// 				buttons[i].changeColor(WHITE);
		// 			}
		// 			else
		// 			{
		// 				buttons[i].changeColor(PINK);
		// 			}
		// 		}
		// 		break;
		// 	}
		// }

		// Clear screen
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer);

		// Render
		background.render(renderer, 0, 0);

		title.render(renderer, SCREEN_WIDTH / 2 - title.getWidth() / 2, SCREEN_HEIGHT / 2 - title.getHeight() / 2 - 200);

		for (int i = 0; i < 3; i++)
		{
			buttons[i].render(renderer);
		}

		// Update screen
		SDL_RenderPresent(renderer);
	}
}

void quit()
{
	// Destroy window
	SDL_DestroyWindow(window);
	window = nullptr;

	// Destroy renderer
	SDL_DestroyRenderer(renderer);
	renderer = nullptr;

	// Quit SDL subsystems
	SDL_Quit();
	IMG_Quit();
	TTF_Quit();
	Mix_Quit();
}