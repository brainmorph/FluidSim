#include "Particle.h"

// Constructor
Particle::Particle()
{
	pos.x = 0;
	pos.y = 0;
}

void Particle::UpdatePosition()
{
	pos.x++;
	pos.y++;
}