#include <iostream>
#include "Grid.h"

Grid::Grid(int rows, int cols)
{
	mRows = rows;
	mCols = cols;

	mGrid = new int* [mRows];
	for (int i = 0; i < mCols; i++)
	{
		mGrid[i] = new int[cols];
	}

	// Initialize the 2D array
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			mGrid[i][j] = i * cols + j;
		}
	}

	// Access and print the elements of the 2D array
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << mGrid[i][j] << " ";
		}
		std::cout << std::endl;
	}
}