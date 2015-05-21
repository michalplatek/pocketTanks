#include "Renderable.h"


Renderable::Renderable(Config* config)
{
	this->config = config;
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

float Renderable::positionToPixel(float position)
{
	float ratio = config->WINDOW_W / config->LEVEL_SIZE_IN_METRES;
	return position * ratio;
}
