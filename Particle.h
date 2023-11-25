#pragma once
#include "Vector2D.h"

class Particle
{
public:
	Particle();
	void UpdatePositionBasedOnVelocity();

	Vector2D pos;
	Vector2D vel;
	double dt;
};

