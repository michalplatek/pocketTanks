#ifndef _TANK_H_
#define _TANK_H_

#include<Box2D\Box2D.h>
#include<GL\freeglut.h>
#include<cmath>
#include<vector>
#include "World.h"
#include "ObjectData.h"
#include <cstdlib>

class Tank : public Renderable
{
	Config::Players player;
	Config::ShellType loadedShellType;
	Config::Direction movementHorizontal;
	Config::Direction movementVertical;
	std::vector<b2Body*> wheels;
	std::vector<b2Joint*> joints;
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
	void setHorizontalDirection(Config::Direction direction);
	void setVerticalDirection(Config::Direction direction);
};

#endif