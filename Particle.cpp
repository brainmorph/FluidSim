#include "Particle.h"

// Constructor
Particle::Particle()
	: pos(0, 0), vel(1, 1), acc(0,0), dt(0.1)
{
	pos.Set_x(0.0);
	pos.Set_y(0.0);
}

void Particle::UpdatePositionBasedOnVelocity()
{
	double old_x = pos.Get_x();
	double old_y = pos.Get_y();

	// Move to new location according to velocity components
	double delta_x = vel.Get_x() * dt;
	double delta_y = vel.Get_y() * dt;

	pos.Set_y(old_y + delta_y);
	pos.Set_x(old_x + delta_x);
}

void Particle::UpdateVelocityBasedOnAcceleration()
{
	double old_vx = vel.Get_x();
	double old_vy = vel.Get_y();

	// Update velocity according to acceleration componenets
	double delta_vx = acc.Get_x() * dt;
	double delta_vy = acc.Get_y() * dt;

	vel.Set_x(old_vx + delta_vx);
	vel.Set_y(old_vy + delta_vy);
}