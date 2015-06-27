#ifndef _BARREL_H_
#define _BARREL_H_

#include<Box2D\Box2D.h>
#include<GL\freeglut.h>
#include<cmath>
#include<vector>
#include "World.h"
#include "ObjectData.h"
#include <cstdlib>


class Barrel : public Renderable
{
	float BarrelAngle;

	void GenerateWheel(float radius, b2Vec2 position);
	void GenerateBarrel(float radius, b2Vec2 pos);
public:
	//class member variables

	Barrel(b2World* world, Config* config, Config::Players player);

	void rotate(float angle);

	Barrel();
	~Barrel();
	void render();
	b2Vec2 getBarrelEndPosition();
	float getBarrelAngle();


};

#endif