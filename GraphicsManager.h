#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "IDrawableObject.h"

class GraphicsManager
{
public:
	GraphicsManager();
	int RunSDL();

private:
	int RunApplication();
	void DrawAndPushToScreen(SDL_Renderer* renderer, SDL_Rect& rect, SDL_Texture* texture);
	void DrawTexture(SDL_Texture* texture, SDL_Rect& rect, SDL_Renderer* renderer);
	void DrawRectangle(SDL_Renderer* renderer, SDL_Rect& rect);
	void PushBufferToScreen(SDL_Renderer* renderer);
	void ClearEntireScreen(SDL_Renderer* renderer);
	SDL_Texture* loadTexture(const char* filename, SDL_Renderer* renderer);
	void blit(SDL_Texture* t, int x, int y, SDL_Renderer* renderer);
	
	int _NumObjectsToDraw = 2;
	IDrawableObject* _DrawableObjects[2];
};