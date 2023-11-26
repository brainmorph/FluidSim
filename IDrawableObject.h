#pragma once

#include <SDL.h>

class IDrawableObject
{
public:
	virtual void Draw(SDL_Renderer* renderer, SDL_Rect& rect) {
		return; // do absolutely nothing in the base class, let classes that implement this interface actually define the logic
	}

	virtual ~IDrawableObject() {}
};

