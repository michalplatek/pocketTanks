#pragma once
#include "Renderable.h"
#include "World.h"

class Shell : public Renderable
{
public:
	Shell(World* world);
	~Shell();

	void render();
	void renderAtBodyPosition();
};

