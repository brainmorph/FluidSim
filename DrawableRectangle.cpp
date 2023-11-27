#include "DrawableRectangle.h"
#include <SDL.h>

void DrawableRectangle::Draw(SDL_Renderer* renderer)
{
	_Rect.x = _PosX;
	_Rect.y = _PosY;
	_Rect.w = _Width;
	_Rect.h = _Height;

	SDL_SetRenderDrawColor(renderer, 200, 40, 40, 255); // set draw color
	SDL_RenderFillRect(renderer, &_Rect);
}

void DrawableRectangle::Move(double newX, double newY)
{
	_PosX = newX;
	_PosY = newY;
}