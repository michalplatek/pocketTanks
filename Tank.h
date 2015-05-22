#ifndef _TANK_H_
#define _TANK_H_

#include<Box2D\Box2D.h>
#include<GL\freeglut.h>
#include<cmath>
#include "World.h"
#include "ObjectData.h"

class Tank : public Renderable
{
	Config::Players player;
	Config::ShellType loadedShellType;
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
	Config::ShellType getLoadedShellType();
	void setLoadedShellType(Config::ShellType shellType);
	b2Vec2 getBarrelEndPosition();
	float getBarrelAngle();
};

#endif