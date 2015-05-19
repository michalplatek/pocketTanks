#include<GL/freeglut.h>
#include "World.h"


World::World(Config* config)
{
	b2World* world = new b2World(b2Vec2(0.0f, config->GRAVITY));
	setWorld(world);

	b2Body* body = NULL;

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(100.0f, 50.0f);
	body = world->CreateBody(&bodyDef);

	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(100.0f, 10.0f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 0.0f;
	fixtureDef.friction = 0.3f;

	body->CreateFixture(&fixtureDef);
	setBody(body);
}


World::~World()
{
	b2World* world = getWorld();
	world->DestroyBody(getBody());
	delete world;
}

void World::render()
{
	b2Body* body = getBody();
	glColor3f(1, 0, 0);//red

	//nose and eyes
	glPointSize(4);
	glBegin(GL_POINTS);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(-0.5f, 0.5f);
	glVertex2f(0.5f, 0.5f);
	glEnd();

	//mouth
	glBegin(GL_LINES);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(-0.16f, -0.6f);
	glVertex2f(0.16f, -0.6f);
	glVertex2f(0.5f, -0.5f);
	glEnd();

	//circle outline
	glBegin(GL_LINE_LOOP);
	for (float a = 0; a < 360 * 3.1415f / 180; a += 30 * 3.1415f / 180)
		glVertex2f(sinf(a)*10, cosf(a)*10);
	glEnd();

	b2Vec2 vel = body->GetLinearVelocity();
	float red = vel.Length() / 20.0f;
	red = fmin(1.0f, red);
	glColor3f(red, 0.5, 0.5);
}


