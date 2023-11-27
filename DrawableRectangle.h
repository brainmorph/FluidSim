#pragma once

#include "IDrawableObject.h"
#include <SDL.h>

class DrawableRectangle : public IDrawableObject
{
public:
	void Draw(SDL_Renderer* renderer) override;
	void Move(double newX, double newY);

private:
	SDL_Rect _Rect = { 100, 100, 200, 200 };
	double _Height = 100;
	double _Width = 100;
	double _PosX = 0;
	double _PosY = 0;
};

