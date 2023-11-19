#include <iostream>
#include "GraphicsManager.h"
#include "Vector2D.h"

using namespace std;

int main(int argc, char* argv[])
{
	Vector2D vec(22.3, 44.5);
	vec.Print();

	GraphicsManager gm;
	
	return gm.RunSDL();
}