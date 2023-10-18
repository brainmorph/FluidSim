#include "WorldState.h"
#include "Particle.h"

#include <iostream>
#include <vector>

using namespace std;

void WorldState::RunWorld()
{
	cout << "How many particles?" << endl;

	int numParticles;
	cin >> numParticles;

	vector<Particle> ParticleMatrix;
	for (int i = 0; i < numParticles; i++)
	{
		ParticleMatrix.push_back(Particle());
	}
}