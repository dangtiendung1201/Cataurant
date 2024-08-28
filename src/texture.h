#ifndef _TEXTURE_H
#define _TEXTURE_H

// C++ libraries
#include <iostream>
// SDL libraries
#if defined(_WIN64) || defined(_WIN32) || defined(__APPLE__)
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#endif

// Texture wrapper class
class Texture
{
public:
	// Initializes variables
	Texture();

	// Deallocates memory
	~Texture();

	// Loads image at specified path
	bool loadFromFile(SDL_Renderer *renderer, std::string path);

	// Creates image from font string
	bool loadFromRenderedText(SDL_Renderer *renderer, std::string textureText, SDL_Color textColor, TTF_Font *textFont);

	bool loadString(SDL_Renderer *renderer, std::string path, std::string str, TTF_Font *textFont);

	// Deallocates texture
	void free();

	// Set color modulation
	void setColor(Uint8 red, Uint8 green, Uint8 blue);

	// Renders texture at given point
	void render(SDL_Renderer *renderer, int x, int y, int width, int height, SDL_Rect *clip, double angle = 0.0, SDL_Point *center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	// Gets image dimensions
	int getWidth();
	int getHeight();

private:
	// The actual hardware texture
	SDL_Texture *texture;

	// Image dimensions
	int width, height;
};
#endif