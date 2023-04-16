#include "ultils.h"

Texture scoreTexture;

int random(const int &min, const int &max)
{
	return rand() % (max - min + 1) + min;
}

void showScore(SDL_Renderer *renderer)
{
	SDL_Color textColor = ORANGE;
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