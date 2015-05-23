#include "Shell.h"
#include "Renderable.h"
#include "World.h"
#include "Tank.h"

Shell::Shell(b2World* world, Config* config, Config::Players player, b2Vec2 position, float angle) : Renderable(config)
{
	setWorld(world);

	b2Body* body;
	body = NULL;

	BodyData* bodyData = new BodyData;
	bodyData->bodyType = Config::BodyType::SHELL;
	bodyData->owner = player;

	//set up dynamic body, store in class variable
	b2BodyDef myBodyDef;
	myBodyDef.type = b2_dynamicBody;
	myBodyDef.bullet = true;
	//start position -> position of barrel
	myBodyDef.position.Set(position.x, position.y);
	myBodyDef.userData = (void*)bodyData;

	body = world->CreateBody(&myBodyDef);
	body->SetTransform(b2Vec2(position.x, position.y), angle);
	body->ApplyLinearImpulse(b2Vec2(-20.0f, 20.0f), b2Vec2(0.0f, 0.0f), true);

	setBody(body);
}


Shell::~Shell()
{
	getWorld()->DestroyBody(getBody());
}

