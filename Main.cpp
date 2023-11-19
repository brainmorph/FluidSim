#include <iostream>
#include <assert.h>     /* assert */
#include "GraphicsManager.h"
#include "Vector2D.h"


using namespace std;

int main(int argc, char* argv[])
{
	// ---- Test code ----
	Vector2D vec(0, 0);
	vec.Print();

	Vector2D vec2(4.5, 10.5);
	vec.Add(vec2);
	vec.Print();

	assert(vec.Get_x() == 4.5);
	assert(vec.Get_y() == 10.4);

	// ---- END ----

	GraphicsManager gm;
	return gm.RunSDL();
}