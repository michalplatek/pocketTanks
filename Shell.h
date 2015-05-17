#pragma once
#include "Renderable.h"
#include "World.h"

class Shell : public Renderable
{
public:
	World* world;
	Shell(World* world);
	~Shell();

	void render();
	void renderAtBodyPosition();
};

