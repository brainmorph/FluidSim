#include <iostream>
#include <SDL.h>
using namespace std;

int CreateAWindow();

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		cout << "SDL initialization failed. SDL Error: " << SDL_GetError();
	}
	else
	{
		cout << "SDL initialization succeeded!";
	}

	cout << "Press any key to open a window.";
	cin.get();

	CreateAWindow();

	cin.get(); // pause here before exiting
	return 0;
}

int CreateAWindow()
{
	SDL_Window* window = SDL_CreateWindow(
		"Title goes here",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		800,
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
		}

		// Application code
		// SDL_Delay(16); // control framerate
	}

	// Clean and destroy SDL
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}