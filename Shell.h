#ifndef _SHELL_H_
#define _SHELL_H_

#include "Renderable.h"
#include "World.h"

class Shell : public Renderable
{
public:
	Shell(b2World* world, Config* config, b2Vec2 position, float angle);
	virtual ~Shell();

	void render();
};

#endif
