#ifndef _RENDERABLE_H_
#define _RENDERABLE_H_
#include <Box2D/Box2D.h>

class Renderable
{
	b2Body* body;
	b2World* world;

public:
	Renderable();
	virtual ~Renderable();
	virtual void render() = 0;

	b2Body* getBody();
	void setBody(b2Body* body);

	b2World* getWorld();
	void setWorld(b2World* world);

	b2Vec2 getBodyPosition();
	float getBodyAngle();
};

#endif
