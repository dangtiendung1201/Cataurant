#ifndef _BUTTON_H
#define _BUTTON_H

// SDL libraries
#if defined(_WIN64) || defined(_WIN32) || defined(__APPLE__)
#include <SDL.h>
#include <SDL_ttf.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#endif
// My libraries
#include "ui.h"

class Button : public UserInterface
{
public:
	Button(const SDL_Rect &rect, const SDL_Color &color, TTF_Font *const font, const SDL_Color &fontColor);

	bool isMouseInside(const int &x, const int &y) const;
	void changeColor(const SDL_Color &color);

private:
	SDL_Point position;
};

#endif