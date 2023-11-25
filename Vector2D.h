#pragma once

class Vector2D
{
public:
	Vector2D(double x, double y);
	void Print();
	double Get_x();
	double Get_y();

	/* Adds 2 vectors together and returns a third */
	void Add(Vector2D RH_Vector);

private:
	double _x;
	double _y;
};