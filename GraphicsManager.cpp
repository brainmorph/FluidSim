#include "GraphicsManager.h"
#include <iostream>
#include "DrawableRectangle.h"
#include "Particle.h"

using namespace std;

GraphicsManager::GraphicsManager()
{
	_DrawableObjects[0] = new DrawableRectangle();
	_DrawableObjects[1] = new DrawableRectangle();
	// TODO: this is a bug waiting to happen, I need to prevent writing outside of the array.
}

int GraphicsManager::RunSDL()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		cout << "SDL initialization failed. SDL Error: " << SDL_GetError() << endl;
	}
	else
	{
		cout << "SDL initialization succeeded!" << endl;
	}

	cout << "\nLaunching the app..." << endl;
	RunApplication();

	//cin.get(); // pause here before exiting
	return 0;
}

int GraphicsManager::RunApplication()
{
	// Create a window
	SDL_Window* window = SDL_CreateWindow(
		"Simulation",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1000,
		600,
		SDL_WINDOW_SHOWN
	);

	// Check to see if it was created
	if (!window)
	{
		cout << "Womp womp, something went wrong with trying to create a SDL_Window.";
		// Potentially spit out more verbose messages here later if needed

		SDL_Quit();
		return -1;
	}

	// Now we need something called a renderer
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); // use hardware acceleration (GPU)
	if (!renderer)
	{
		cout << "Something went wrong while trying to create SDL_Renderer.";
		SDL_DestroyWindow(window);
		SDL_Quit();
		return -1;
	}

	// Now we need to initialize the SDL_image library for loading images
	IMG_Init(IMG_INIT_PNG);
	SDL_Texture* texture = loadTexture("gfx/test.png", renderer);
	SDL_Texture* texture2 = loadTexture("gfx/sphere_small.png", renderer);

	// At this point we have a renderer, we can start drawing to it.
	SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255);
	SDL_RenderClear(renderer);

	SDL_Rect rect = { 100, 100, 200, 200 };
	SDL_SetRenderDrawColor(renderer, 200, 40, 40, 255);
	SDL_RenderFillRect(renderer, &rect);

	PushBufferToScreen(renderer);

	// Prep for main loop
	bool quit = false;
	SDL_Event e;

	Particle pArray[100]; // scoped to this function

	// Main loop where everything happens
	while (!quit)
	{
		HandleInputEvents(e, quit, rect);


		// ---- Application code ----
		ClearEntireScreen(renderer);

		// I need access to the particle array at this point...
		// Where is the particle array currently?
		for (int i = 0; i < 100; i++)
		{
			pArray[i].UpdatePositionBasedOnVelocity();
			pArray[i].UpdateVelocityBasedOnAcceleration();

			rect.x = pArray[i].pos.Get_x() + i*10;
			rect.y = pArray[i].pos.Get_y() + i*10;
			

			_DrawableObjects[i]->Draw(renderer);
			PushBufferToScreen(renderer);

			SDL_Delay(16); // control framerate
		}


		// ----
	}

	// Clean and destroy SDL
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void GraphicsManager::HandleInputEvents(SDL_Event& e, bool& quit, SDL_Rect& rect)
{
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
		{
			quit = true;
		}
		else if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym == SDLK_w)
			{
				rect.y -= 10;
			}
			else if (e.key.keysym.sym == SDLK_a)
			{
				rect.x -= 10;
			}
			else if (e.key.keysym.sym == SDLK_s)
			{
				rect.y += 10;
			}
			else if (e.key.keysym.sym == SDLK_d)
			{
				rect.x += 10;
			}
		}
	}
}

void GraphicsManager::DrawTexture(SDL_Texture* texture, SDL_Rect& rect, SDL_Renderer* renderer)
{
	blit(texture, rect.x - 10, rect.y - 10, renderer);
}

void GraphicsManager::DrawRectangle(SDL_Renderer* renderer, SDL_Rect& rect)
{
	SDL_SetRenderDrawColor(renderer, 200, 40, 40, 255); // set draw color
	SDL_RenderFillRect(renderer, &rect);
}

void GraphicsManager::PushBufferToScreen(SDL_Renderer* renderer)
{
	SDL_RenderPresent(renderer);
}

void GraphicsManager::ClearEntireScreen(SDL_Renderer* renderer)
{
	// Clear screen
	SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255); // set draw color
	SDL_RenderClear(renderer); // clear renderer with current draw color
}

SDL_Texture* GraphicsManager::loadTexture(const char* filename, SDL_Renderer* renderer)
{
	SDL_Texture* texture;
	cout << "Loading texture..." << endl;

	texture = IMG_LoadTexture(renderer, filename);

	return texture;
}

void GraphicsManager::blit(SDL_Texture* t, int x, int y, SDL_Renderer* renderer)
{
	SDL_Rect dest;

	dest.x = x;
	dest.y = y;
	SDL_QueryTexture(t, NULL, NULL, &dest.w, &dest.h);

	SDL_RenderCopy(renderer, t, NULL, &dest);
}