#include "DrawableRectangle.h"
#include <SDL.h>

void DrawableRectangle::Draw(SDL_Renderer* renderer, SDL_Rect& rect)
{
	SDL_SetRenderDrawColor(renderer, 200, 40, 40, 255); // set draw color
	SDL_RenderFillRect(renderer, &rect);
}