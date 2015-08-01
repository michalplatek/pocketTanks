#ifndef _TANK_H_
#define _TANK_H_

#include<Box2D\Box2D.h>
#include<GL\freeglut.h>
#include<cmath>
#include<vector>
#include "World.h"
#include "ObjectData.h"
#include <cstdlib>
#include "Barrel.h"
#include "Wheel.h"

class Tank : public Renderable
{
	Config::Players player;
	Config::ShellType loadedShellType;
	Config::Direction movementHorizontal;
	Config::Direction movementVertical;
	std::vector<b2Joint*> joints;




	void GenerateWheel(float radius, b2Vec2 position, b2Vec2 anchor);
	void GenerateBarrel(float radius, b2Vec2 pos, int direction);
public:
	//class member variables
	float radius;
	Barrel* barrel;
	std::vector<Wheel*> wheels;
	Tank(b2World* world, Config* config, Config::Players player);

	int healthPoints;
	b2Vec3 color;

	/*b2Vec2 getPosition();
	b2Vec2 getLinearVelocity();
	float getAngle();*/

	Tank();
	~Tank();
	void render();
	Config::ShellType getLoadedShellType();
	void setLoadedShellType(Config::ShellType shellType);
	b2Vec2 getBarrelEndPosition();
	Config::Direction getHorizontalDorection();
	float getBarrelAngle();

	void stop();
	void setHorizontalDirection(Config::Direction direction);
	void setVerticalDirection(Config::Direction direction);


};

#endif