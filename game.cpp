#include "game.h"

int gameState;

SDL_Window *window;
SDL_Renderer *renderer;

// Declearation
TTF_Font *menuFont,			  // Menu font
	*titleFont, *versionFont; // Title font

Texture title, version; // Title texture

Texture background, musicOn, soundOn, musicOff, soundOff, gameground, stand; // Background texture

Mix_Music *music; // Music
Mix_Chunk *sound; // Sound

const char *menuText[NUM_BUTTONS] = {"Play", "Help", "Quit"}; // Menu text

bool musicState = ON;
bool soundState = ON;

Seller seller;
Customer customer[5];
Dishes dish;

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

void loadMusic(Mix_Music *&music, const char *path)
{
	music = Mix_LoadMUS(path);
	if (music == nullptr)
	{
		std::cout << "Failed to load music! Error: " << Mix_GetError() << std::endl;
	}
}

void loadSound(Mix_Chunk *&sound, const char *path)
{
	sound = Mix_LoadWAV(path);
	if (sound == nullptr)
	{
		std::cout << "Failed to load sound! Error: " << Mix_GetError() << std::endl;
	}
}

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
		window = SDL_CreateWindow("Cataurant", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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

	// Load music
	loadMusic(music, "assets/sounds/music.wav");
	loadSound(sound, "assets/sounds/sound.wav");

	// Load font
	loadFont(menuFont, "assets/fonts/menu.ttf", MENU_SIZE);
	loadFont(titleFont, "assets/fonts/title.ttf", TITLE_SIZE);
	loadFont(versionFont, "assets/fonts/version.ttf", VERSION_SIZE);

	// Load images
	loadImage(background, "assets/images/background.png");
	loadImage(musicOn, "assets/icons/musicOn.png");
	loadImage(soundOn, "assets/icons/soundOn.png");
	loadImage(musicOff, "assets/icons/musicOff.png");
	loadImage(soundOff, "assets/icons/soundOff.png");
	loadImage(gameground, "assets/images/gameground.png");
	loadImage(stand, "assets/images/stand.png");

	// Load texts
	title.loadFromRenderedText(renderer, "Cataurant", ORANGE, titleFont);
	version.loadFromRenderedText(renderer, "VERSION: 1.0", BLACK, versionFont);

	Mix_PlayMusic(music, -1);

	return success;
}

void game()
{
	gameState = PLAY;
	Uint32 frameStart, frameTime;
	seller.loadTexture(renderer);
	seller.init();

	dish.loadTexture(renderer);
	dish.init();

	for (int i = 0; i < 5; i++)
	{
		customer[i].loadTexture(renderer, i % 2);
		customer[i].setMotion();
	}

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
				quit = true;
				break;
			}
			seller.handleEvent(renderer, event);
		}

		// Clear screen
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer);

		// Render
		gameground.render(renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
		// render seller equivalent to stand and dishes
		seller.render(renderer);

		// seller.render(renderer, SCREEN_WIDTH / 2 - seller.getWidth() / 2, SCREEN_HEIGHT / 2 - seller.getHeight() / 2, seller.getWidth() / 2, seller.getHeight() / 2);
		stand.render(renderer, SCREEN_WIDTH / 2 - stand.getWidth() / 2, SCREEN_HEIGHT / 2 - stand.getHeight() / 2, stand.getWidth(), stand.getHeight(), NULL);

		// render customers
		for (int i = 0; i < 5; i++)
		{
			customer[i].render(renderer, i);
		}

		seller.renderDeque(renderer);
		dish.render(renderer);
		// Update screen
		SDL_RenderPresent(renderer);
		// Frame rate
		frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < DELAY_TIME)
		{
			SDL_Delay(DELAY_TIME - frameTime);
		}
	}
}

void menu()
{
	gameState = MENU;

	Uint32 frameStart, frameTime;

	// Const
	const int NUM_BUTTONS = 3; // Number of buttons

	std::vector<Button> buttons; // Menu buttons

	// Load buttons
	for (int i = 0; i < NUM_BUTTONS; i++)
	{
		SDL_Rect rect = {SCREEN_WIDTH / 2 - BUTTON_WIDTH / 2, SCREEN_HEIGHT / 2 - BUTTON_HEIGHT / 2 + i * (BUTTON_HEIGHT + 50), BUTTON_WIDTH, BUTTON_HEIGHT};
		Button button(rect, PINK, menuFont, ORANGE);
		button.loadTexture(renderer, menuText[i]);
		// set button position

		buttons.push_back(button);
	}

	SDL_Rect musicRect = {MUSIC_POSX, MUSIC_POSY, MUSIC_WIDTH, MUSIC_HEIGHT};
	SDL_Rect soundRect = {SOUND_POSX, SOUND_POSY, SOUND_WIDTH, SOUND_HEIGHT};
	Button musicButton(musicRect, TRANSPARENT, menuFont, TRANSPARENT);
	Button soundButton(soundRect, TRANSPARENT, menuFont, TRANSPARENT);

	musicButton.loadTexture(renderer, "");
	soundButton.loadTexture(renderer, "");

	// Main loop
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
						if (soundState == ON)
							Mix_PlayChannel(-1, sound, 0);
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
						soundState = OFF;
					}
					else
					{
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
							game();
							std::cout << "Play" << std::endl;
							break;
						case 1:
							// help();
							std::cout << "Help" << std::endl;
							break;
						case 2:
							// quit();
							quit = true;
							std::cout << "Quit" << std::endl;
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

		for (int i = 0; i < 3; i++)
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
		if (gameState != MENU)
			quit = true;
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