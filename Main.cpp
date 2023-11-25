#include <iostream>
#include <assert.h>     /* assert */
#include "GraphicsManager.h"
#include "Vector2D.h"
#include "Particle.h"


using namespace std;

int main(int argc, char* argv[])
{
	// ---- Test code ----

	Particle pArray[100];
	
	while (true)
	{
		for (int i = 0; i < 100; i++)
		{
			pArray[i].UpdatePositionBasedOnVelocity();
		}
	}
	// ---- END ----

	GraphicsManager gm;
	return gm.RunSDL(); // never exits
}