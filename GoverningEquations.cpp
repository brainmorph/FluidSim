#include "GoverningEquations.h"

GoverningEquations::GoverningEquations()
{

}

double GoverningEquations::density_rho_i(std::vector<double> massMatrix,std::vector<std::vector<double>>& wMatrix)
{
	double density = 0.0;

	for (int i = 0; i < massMatrix.size(); i++)
	{
		density += massMatrix[i];

		// Log info
		std::cout << "massMatrix[" << i << "] = " << massMatrix[i] << std::endl;
	}

	std::cout << "The density of particle i is: " << density << std::endl;
	return density;
}

std::vector<double> GoverningEquations::initialize1DMatrix(int size)
{
	std::cout << "Creating 1D vector with " << size << " rows." << std::endl;

	std::vector<double> newVector;

	for (int i = 0; i < size; i++)
	{
		std::cout << "At row[" << i << "]" << std::endl;
		newVector.push_back(i);
	}

	return newVector;
}

std::vector<std::vector<double>> GoverningEquations::initialize2DMatrix(int size_i, int size_j)
{
	std::cout << "Creating 2D vector with " << size_i << " rows and " << size_j << " columns." << std::endl;

	std::vector<std::vector<double>> newVector;

	for (int i = 0; i < size_i; i++)
	{
		std::cout << "At row[" << i << "]" << std::endl;
		std::vector<double> row;

		for (int j = 0; j < size_j; j++)
		{
			std::cout << "    at column[" << j << "]" << std::endl;
			row.push_back(i * size_j + j);
		}
		newVector.push_back(row);
	}

	return newVector;
}