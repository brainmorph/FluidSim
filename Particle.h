#pragma once

class Particle
{
public:
	Particle();
	void UpdatePosition();

	// in C++ you can make structs act as datatypes if you name the struct like this
	struct Position{ 
		double x;
		double y;
	};

	Position pos; // then later you can use the struct as a datatype
};

