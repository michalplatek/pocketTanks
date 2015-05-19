#ifndef _WORLD_H_
#define _WORLD_H_

#include <Box2D/Box2D.h>
#include "Config.h"
#include "Renderable.h"

class World : public Renderable
{
public:
	World(Config* config);
	~World();

	void render();
};

#endif
