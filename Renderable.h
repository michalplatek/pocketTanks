#ifndef _RENDERABLE_H_
#define _RENDERABLE_H_
#include <Box2D/Box2D.h>
#include "Config.h"

class Renderable
{
protected:

	b2Body* body;
	b2World* world;
	Config* config;

public:
	Renderable(Config* config);
	virtual ~Renderable();
	virtual void render() = 0;

	b2Body* getBody();
	void setBody(b2Body* body);

	b2World* getWorld();
	void setWorld(b2World* world);

	b2Vec2 getBodyPosition();
	float getBodyAngle();

	Config* getConfig();
};

#endif
