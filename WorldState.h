#pragma once

#include <vector>
#include "Particle.h"

class WorldState
{
public:
	void StartWorld();
	void RunWorld();

	std::vector<Particle> ParticleMatrix;
};

