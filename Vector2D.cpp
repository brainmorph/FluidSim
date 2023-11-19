#include <iostream>
#include "Vector2D.h"

using namespace std;

Vector2D::Vector2D(double x, double y)
{
	_x = x;
	_y = y;
}

void Vector2D::Print()
{
	cout << "x: " << _x << endl;
	cout << "y: " << _y << endl;
}