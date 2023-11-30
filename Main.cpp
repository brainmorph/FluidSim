#include <iostream>
#include <assert.h>     /* assert */
#include "GraphicsManager.h"
#include "Vector2D.h"
#include "Particle.h"


using namespace std;

int main(int argc, char* argv[])
{
	GraphicsManager gm;
	return gm.RunSDL(); // never exits
}