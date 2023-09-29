#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
using namespace std;

int CreateAnApp();
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

	cout << "\nLaunching the app..." << endl;

	CreateAnApp();

	cin.get(); // pause here before exiting
	return 0;
}

int CreateAnApp()
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
					rect.y -= 1;
				}
			}
		}
		
		// ---- Application code
		
		// Clear screen
		SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255); // set draw color
		SDL_RenderClear(renderer); // clear renderer with current draw color

		// Move rectangle and redraw it
		rect.x += 1;
		SDL_SetRenderDrawColor(renderer, 200, 40, 40, 255); // set draw color
		SDL_RenderFillRect(renderer, &rect);
		
		// Draw texture
		blit(texture, rect.x - 10, rect.y - 10, renderer);

		// Paint screen
		SDL_RenderPresent(renderer);


		SDL_Delay(256); // control framerate

		// ----
	}

	// Clean and destroy SDL
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
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