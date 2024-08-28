#ifndef _UI_H
#define _UI_H

// C++ libraries
#include <iostream>
// SDL libraries
#if defined(_WIN64) || defined(_WIN32) || defined(__APPLE__)
#include <SDL.h>
#include <SDL_ttf.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#endif

class UserInterface
{
protected:
	SDL_Rect mRect;
	SDL_Color mColor;

	// Texture to show text
	TTF_Font *mFont;
	SDL_Rect mFontRect;
	SDL_Color mFontColor;
	SDL_Texture *mTexture;

	void centerText();

public:
	UserInterface(const SDL_Rect &rect, const SDL_Color &color, TTF_Font *const font, const SDL_Color &fontColor);

	void loadTexture(SDL_Renderer *const renderer, const char *text);
	void render(SDL_Renderer *const renderer) const;
	void free();
};

#endif