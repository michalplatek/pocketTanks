#ifndef _PARTICLE_H_
#define _PARTICLE_H_
#include "Renderable.h"
#include "World.h"

class Particle : public Renderable
{

public:
	Particle(Config* config);
	~Particle();

	void render();
};

#endif
