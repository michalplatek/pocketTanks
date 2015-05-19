#ifndef _SHELL_H_
#define _SHELL_H_

#include "Renderable.h"
#include "World.h"

class Shell : public Renderable
{
public:
	Shell(b2World* world);
	~Shell();

	void render();
};

#endif
