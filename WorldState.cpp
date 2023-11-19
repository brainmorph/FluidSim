#include "WorldState.h"
#include "Particle.h"

#include <iostream>
#include <vector>

using namespace std;

void WorldState::StartWorld()
{
	int numParticles;
	cout << "How many particles?" << endl;
	cin >> numParticles;

	for (int i = 0; i < numParticles; i++)
	{
		ParticleMatrix.push_back(Particle());
	}
}

void WorldState::RunWorld()
{
	// At this point we have a bunch of particles inside an array
	for(Particle p : ParticleMatrix)
	{
		p.UpdatePosition();
	}
}