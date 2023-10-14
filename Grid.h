#pragma once

class Grid
{
public:
	Grid(int rows, int cols);

private:
	int mRows;
	int mCols;

	// 2D Vector
	int** mGrid;
};