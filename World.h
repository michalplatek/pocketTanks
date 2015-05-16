#pragma once
#include <Box2D/Box2D.h>
#include "Config.h"
#include "Renderable.h"

class World : public b2World, public Renderable
{
	b2Body* body;
public:
	World(Config* config);
	~World();

	void render();
	void renderAtBodyPosition();
};

