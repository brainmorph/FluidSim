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
		cout << "Womp womp";
		// Potentially spit out more verbose messages here later if needed
		
		SDL_Quit();
		return -1;
	}

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
	SDL_DestroyWindow(window);
	SDL_Quit();
}