#include "Shell.h"
#include "Renderable.h"
#include "World.h"
#include "Tank.h"

Shell::Shell(b2World* world, Config* config, b2Vec2 position, float angle) : Renderable(config)
{
	setWorld(world);

	b2Body* body;
	body = NULL;

	float positionBarrelX = 0;
	float positionBarrelY = 0;

	//set up dynamic body, store in class variable
	b2BodyDef myBodyDef;
	myBodyDef.type = b2_dynamicBody;
	//start position -> position of barrel
	myBodyDef.position.Set(positionBarrelX, positionBarrelY);

	body = world->CreateBody(&myBodyDef);
}


Shell::~Shell()
{
	getWorld()->DestroyBody(getBody());
}

void Shell::render()
{
	b2Body* body = getBody();
}



