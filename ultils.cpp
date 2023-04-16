#include "ultils.h"

Texture scoreTexture;

void loadFont(TTF_Font *&font, const char *path, const int &size)
{
	font = TTF_OpenFont(path, size);
	if (font == nullptr)
	{
		std::cout << "Failed to load font! Error: " << TTF_GetError() << std::endl;
	}
}

void loadImage(SDL_Renderer *renderer, Texture &texture, const char *path)
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

int random(const int &min, const int &max)
{
	return rand() % (max - min + 1) + min;
}

void showLive(SDL_Renderer *renderer)
{
	for (int i = 0; i < live; i++)
	{
		heart.render(renderer, LIVE_POSX + i * LIVE_DISTANCE, LIVE_POSY, LIVE_WIDTH, LIVE_HEIGHT, NULL);
	}
}

void showScore(SDL_Renderer *renderer)
{
	SDL_Color textColor = YELLOW;
	std::string scoreText = "Score: " + std::to_string(score);
	scoreTexture.loadFromRenderedText(renderer, scoreText, textColor, scoreFont);
	scoreTexture.render(renderer, SCORE_POSX, SCORE_POSY, scoreTexture.getWidth(), scoreTexture.getHeight(), NULL);
}

void readHighestScore()
{
	std::ifstream file;
	file.open("assets/highestScore.txt");

	if (file.is_open())
		file >> highestScore;

	file.close();
}

void updateHighestScore()
{
	if (score > highestScore)
	{
		highestScore = score;
		std::ofstream file;
		file.open("assets/highestScore.txt");

		if (file.is_open())
			file << highestScore;

		file.close();
	}
}

void showHighestScore(SDL_Renderer *renderer)
{
	SDL_Color textColor = ORANGE;
	std::string highestScoreText = "Highest Score: " + std::to_string(highestScore);
	scoreTexture.loadFromRenderedText(renderer, highestScoreText, textColor, highestScoreFont);
	scoreTexture.render(renderer, HIGHEST_SCORE_POSX, HIGHEST_SCORE_POSY, scoreTexture.getWidth(), scoreTexture.getHeight(), NULL);
}

void levelUp()
{
	if (score >= LEVEL_POINT[level] && level < MAX_LEVEL)
	{
		level++;
		Mix_PlayChannel(-1, levelSound, 0);
	}
}