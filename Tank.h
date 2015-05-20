#ifndef _TANK_H_
#define _TANK_H_

#include<Box2D\Box2D.h>
#include<GL\freeglut.h>
#include<cmath>
#include "World.h"

class Tank : public Renderable
{
	Config::Players player;
public:
	//class member variables
	float radius;

	Tank(b2World* world, Config* config, Config::Players player);

	/*b2Vec2 getPosition();
	b2Vec2 getLinearVelocity();
	float getAngle();*/

	Tank();
	~Tank();
	void render();
};

#endif