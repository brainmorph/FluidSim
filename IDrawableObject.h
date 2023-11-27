#pragma once

#include <SDL.h>

class IDrawableObject
{
public:
	virtual void Draw(SDL_Renderer* renderer) = 0; // pure virtual function to force subclasses to implement it
	virtual void Move(double newX, double newY) = 0; // pure virtual function to force subclasses to implement it

	virtual ~IDrawableObject() {}
};

