#include "Particle.h"

// Constructor
Particle::Particle()
	: pos(0, 0), vel(1, 1), dt(0.1)
{
	pos.Set_x(0.0);
	pos.Set_y(0.0);
}

void Particle::UpdatePositionBasedOnVelocity()
{
	double old_x = pos.Get_x();
	double old_y = pos.Get_y();

	// Move to new x location according to velocity in x
	double delta_x = vel.Get_x() * dt;
	pos.Set_x(old_x + delta_x);

	// Move to new y location according to velocity in y
	double delta_y = vel.Get_y() * dt;
	pos.Set_y(old_y + delta_y);
}