#pragma once

#include "IDrawableObject.h"
#include <SDL.h>

class DrawableRectangle : public IDrawableObject
{
public:
	void Draw(SDL_Renderer* renderer, SDL_Rect& rect) override;
};

