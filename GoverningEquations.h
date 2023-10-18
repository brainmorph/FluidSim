#pragma once

#include <iostream>
#include <vector>

class GoverningEquations
{
public:
	GoverningEquations();
	double density_rho_i(std::vector<double> massMatrix, std::vector<std::vector<double>>& wMatrix);
	double kernel_omega_ij(double r);

	std::vector<double> initialize1DMatrix(int size);
	std::vector<std::vector<double>> initialize2DMatrix(int size_i, int size_j);

private:
};