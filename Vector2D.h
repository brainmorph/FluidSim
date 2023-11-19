#pragma once

class Vector2D
{
public:
	Vector2D(double x, double y);
	void Print();
	double Get_x();
	double Get_y();
	Vector2D* Add(Vector2D RH_Vector);

private:
	double _x;
	double _y;
};