#pragma once

class Grid
{
public:
	int Rows;
	int Cols;
	Grid(int rows, int cols);

private:
	// 2D Vector
	int** mGrid;
};