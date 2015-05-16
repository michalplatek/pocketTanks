#pragma once
#include<Box2D\Box2D.h>
#include<GL\freeglut.h>
#include<cmath>
#include "World.h"

class Tank : public Renderable
{
public:
	//class member variables
	b2Body* body;
	float radius;

	Tank(World* world);

	/*b2Vec2 getPosition();
	b2Vec2 getLinearVelocity();
	float getAngle();*/

	Tank();
	~Tank();
	void render();
	void renderAtBodyPosition();
};

