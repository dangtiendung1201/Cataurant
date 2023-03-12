#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include "ui.h"

class Button : public UserInterface
{
public:
    Button(const SDL_Rect &rect, const SDL_Color &colour, TTF_Font *const font, const SDL_Color &fontColour);

    bool isMouseInside(const int x, const int y) const;
    void changeColourTo(const SDL_Colour &colour);
};