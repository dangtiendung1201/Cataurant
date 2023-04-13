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