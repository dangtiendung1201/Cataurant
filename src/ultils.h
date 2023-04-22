#ifndef _ULTILS_H
#define _ULTILS_H

// C++ libraries
#include <string>
#include <stdlib.h>
#include <fstream>
#include <ostream>
// My libraries
#include "game.h"
#include "texture.h"
#include "const.h"

extern int score;
extern int level;
extern int live;
extern int highestScore;

void loadFont(TTF_Font *&font, const char *path, const int &size);
void loadImage(SDL_Renderer *renderer, Texture &texture, const char *path);
void loadMusic(Mix_Music *&music, const char *path);
void loadSound(Mix_Chunk *&sound, const char *path);


int random(const int &min, const int &max);

void showLive(SDL_Renderer *renderer);

void showScore(SDL_Renderer *renderer);

void readHighestScore();
void updateHighestScore();
void showHighestScore(SDL_Renderer *renderer);

void levelUp();

#endif