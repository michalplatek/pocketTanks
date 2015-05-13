#pragma once
#include <Box2D/Box2D.h>
#include "Config.h"
class World : public b2World
{
	b2Body* body;
public:
	World(Config* config);
	~World();
};

