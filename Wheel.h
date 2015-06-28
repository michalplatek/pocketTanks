#ifndef _WHEEL_H_
#define _WHEEL_H_

#include<Box2D\Box2D.h>
#include<GL\freeglut.h>
#include<cmath>
#include<vector>
#include "World.h"
#include "ObjectData.h"
#include <cstdlib>


class Wheel : public Renderable
{
	float radius;


public:
	//class member variables

	Wheel(b2World* world, Config* config, Config::Players player, float radius);

	void rotate(float angle);

	Wheel();
	~Wheel();
	void render();



};

#endif 