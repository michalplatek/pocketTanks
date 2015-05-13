#pragma once
#include<Box2D\Box2D.h>
#include<GL\freeglut.h>
#include<cmath>

class Tank
{
public:
	//class member variables
	b2Body* m_body;
	float m_radius;

	Tank(b2World* world, float radius);
	void render();
	void renderAtBodyPosition();
	Tank();
	~Tank();
};

