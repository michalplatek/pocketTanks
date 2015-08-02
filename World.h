#ifndef _WORLD_H_
#define _WORLD_H_

#include <Box2D/Box2D.h>
#include "Config.h"
#include "Renderable.h"
#include "ObjectData.h"
#include "Geometry.h"

class World : public Renderable
{
public:
	World(Config* config);
	~World();

	std::unique_ptr<b2ChainShape> makeChain(b2Vec2* points, int count, bool closed);
	void render();
	unordered_set<b2Body*> getDestructibleBodies(b2Vec2 position, float radius);
};

#endif
