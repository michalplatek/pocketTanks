#include "Renderable.h"


Renderable::Renderable(Config* config) :config(config)
{
}


Renderable::~Renderable()
{
}

b2Body* Renderable::getBody()
{
	return body;
}

void Renderable::setBody(b2Body* body)
{
	this->body = body;
}

b2World* Renderable::getWorld()
{
	return world;
}

void Renderable::setWorld(b2World* world)
{
	this->world = world;
}

b2Vec2 Renderable::getBodyPosition()
{
	return getBody()->GetPosition();
}

float Renderable::getBodyAngle()
{
	return getBody()->GetAngle();
}

Config* Renderable::getConfig()
{
	return config;
}