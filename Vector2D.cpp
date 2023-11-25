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

double Vector2D::Get_x()
{
	return _x;
}

double Vector2D::Get_y()
{
	return _y;
}

void Vector2D::Set_x(double x)
{
	_x = x;
}

void Vector2D::Set_y(double y)
{
	_y = y;
}

void Vector2D::Add(Vector2D RH_Vector)
{
	_x += RH_Vector.Get_x();
	_y += RH_Vector.Get_y();
}