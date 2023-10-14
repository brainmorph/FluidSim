#include <iostream>
#include "Grid.h"

Grid::Grid(int rows, int cols)
{
	Rows = rows;
	Cols = cols;

	mGrid = new int* [Rows];
	for (int i = 0; i < Rows; i++)
	{
		mGrid[i] = new int[Cols];
	}

	// Initialize the 2D array
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			mGrid[i][j] = i * Cols + j;
		}
	}

	// Access and print the elements of the 2D array
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			std::cout << mGrid[i][j] << " ";
		}
		std::cout << std::endl;
	}
}