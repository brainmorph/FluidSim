#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "Grid.h"
#include "GoverningEquations.h"

using namespace std;

int RunApplication();
void Update(SDL_Renderer* renderer, SDL_Rect& rect, SDL_Texture* texture);
void DrawTexture(SDL_Texture* texture, SDL_Rect& rect, SDL_Renderer* renderer);
void DrawRectangle(SDL_Renderer* renderer, SDL_Rect& rect);
void PushBufferToScreen(SDL_Renderer* renderer);
void ClearEntireScreen(SDL_Renderer* renderer);
SDL_Texture* loadTexture(const char*, SDL_Renderer*);
void blit(SDL_Texture*, int, int, SDL_Renderer*);

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		cout << "SDL initialization failed. SDL Error: " << SDL_GetError() << endl;
	}
	else
	{
		cout << "SDL initialization succeeded!" << endl;
	}

	// ---- HIGHLY EXPERIMENTAL ----
	cout << "\nCreating Grid..." << endl;
	Grid* g = new Grid(3, 20);
	cout << "Grid has: " << g->Rows << " rows and " << g->Cols << " columns." << endl;


	cout << "\nRunning test equations..." << endl;
	GoverningEquations* ge = new GoverningEquations();
	vector<double> massMatrix = ge->initialize1DMatrix(3);
	vector<vector<double>> wMatrix = ge->initialize2DMatrix(10, 2);
	//ge->density_rho_i(massMatrix, wMatrix);
	// ----

	cout << "\nLaunching the app..." << endl;
	RunApplication();

	//cin.get(); // pause here before exiting
	return 0;
}

int RunApplication()
{
	// Create a window
	SDL_Window* window = SDL_CreateWindow(
		"Title goes here",
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

	// At this point we have a renderer, we can start drawing to it.
	SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255); // set draw color
	SDL_RenderClear(renderer); // clear renderer with current draw color

	SDL_Rect rect = { 100, 100, 200, 200 };
	SDL_SetRenderDrawColor(renderer, 200, 40, 40, 255); // set draw color
	SDL_RenderFillRect(renderer, &rect);

	SDL_RenderPresent(renderer); // update screen

	// Main loop
	bool quit = false;
	SDL_Event e;
	while (!quit)
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
		
		// ---- Application code ----
		Update(renderer, rect, texture);
		SDL_Delay(16); // control framerate
		// ----
	}

	// Clean and destroy SDL
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

/// <summary>
/// Application logic for each frame
/// </summary>
/// <param name="renderer"></param>
/// <param name="rect"></param>
/// <param name="texture"></param>
void Update(SDL_Renderer* renderer, SDL_Rect& rect, SDL_Texture* texture)
{
	ClearEntireScreen(renderer);

	// Choose color and draw rectangle
	DrawRectangle(renderer, rect);

	// Draw texture
	DrawTexture(texture, rect, renderer);

	// Push to screen
	PushBufferToScreen(renderer);
}

void DrawTexture(SDL_Texture* texture, SDL_Rect& rect, SDL_Renderer* renderer)
{
	blit(texture, rect.x - 10, rect.y - 10, renderer);
}

void DrawRectangle(SDL_Renderer* renderer, SDL_Rect& rect)
{
	SDL_SetRenderDrawColor(renderer, 200, 40, 40, 255); // set draw color
	SDL_RenderFillRect(renderer, &rect);
}

void PushBufferToScreen(SDL_Renderer* renderer)
{
	SDL_RenderPresent(renderer);
}

void ClearEntireScreen(SDL_Renderer* renderer)
{
	// Clear screen
	SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255); // set draw color
	SDL_RenderClear(renderer); // clear renderer with current draw color
}

SDL_Texture* loadTexture(const char* filename, SDL_Renderer* renderer)
{
	SDL_Texture* texture;
	cout << "Loading texture..." << endl;
	
	texture = IMG_LoadTexture(renderer, filename);

	return texture;
}

void blit(SDL_Texture* t, int x, int y, SDL_Renderer* renderer)
{
	SDL_Rect dest;

	dest.x = x;
	dest.y = y;
	SDL_QueryTexture(t, NULL, NULL, &dest.w, &dest.h);

	SDL_RenderCopy(renderer, t, NULL, &dest);
}