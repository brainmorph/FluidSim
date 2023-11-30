#pragma once

#include "IDrawableObject.h"
#include <SDL.h>

class DrawableRectangle : public IDrawableObject
{
public:
	DrawableRectangle(int width, int height);
	void Draw(SDL_Renderer* renderer) override;
	void Move(double newX, double newY);

private:
	SDL_Rect _Rect = { 100, 100, 200, 200 };
	double _Height;
	double _Width;
	double _PosX = 0;
	double _PosY = 0;
};

