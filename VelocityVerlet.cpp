#include "VelocityVerlet.h"

double DerivativeOfU(double r)
{
	return 1;
}

double Fnet(double r)
{
	return DerivativeOfU(r) * -1.0;
}

double Vnext(double r)
{
	double a = Fnet(r) / mass;
}