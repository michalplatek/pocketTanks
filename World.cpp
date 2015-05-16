#include "World.h"


World::World(Config* config) : b2World(b2Vec2(0.0f, config->GRAVITY))
{

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(0.0f, 4.0f);
	body = this->CreateBody(&bodyDef);

	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;

	body->CreateFixture(&fixtureDef);
}


World::~World()
{
	this->DestroyBody(body);
}

void World::render()
{

}

void World::renderAtBodyPosition()
{

}