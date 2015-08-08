#ifndef _HESHELL_H_
#define _HESHELL_H_

#include "Shell.h"
#include "GL\freeglut.h"

	// High Explosive Shell

class HEShell : public Shell
{
public:
	float radius;

	HEShell(b2World* world, Config* config, Config::Players player, b2Vec2 position, float angle, int shellVelocity);
	~HEShell();

	void render();
};

#endif
