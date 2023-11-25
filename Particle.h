#pragma once
#include "Vector2D.h"

class Particle
{
public:
	Particle();
	void UpdatePositionBasedOnVelocity();
	void UpdateVelocityBasedOnAcceleration();

	Vector2D pos;
	Vector2D vel;
	Vector2D acc;
	double dt;
};

