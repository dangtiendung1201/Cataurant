#include "ultils.h"

Texture scoreTexture;

int random(int min, int max)
{
    return min + (rand() % static_cast<int>(max - min + 1));
}

void showScore(SDL_Renderer *renderer)
{
    SDL_Color textColor = ORANGE;
    std::string scoreText = "Score: " + std::to_string(score);
    scoreTexture.loadFromRenderedText(renderer, scoreText, textColor, scoreFont);
    scoreTexture.render(renderer, SCORE_POSX, SCORE_POSY, scoreTexture.getWidth(), scoreTexture.getHeight(), NULL);
}