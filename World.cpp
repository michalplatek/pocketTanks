#include<GL/freeglut.h>
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
		glVertex2f(sinf(a), cosf(a));
	glEnd();

	b2Vec2 vel = body->GetLinearVelocity();
	float red = vel.Length() / 20.0f;
	red = fmin(1.0f, red);
	glColor3f(red, 0.5, 0.5);
}

void World::renderAtBodyPosition()
{
	//get current position from Box2D
	b2Vec2 pos = body->GetPosition();
	float angle = body->GetAngle();

	//call normal render at different position/rotation
	glPushMatrix();
	glTranslatef(pos.x, pos.y, 0);
	glRotatef(angle * 180 / 3.1415f, 0, 0, 1);//OpenGL uses degrees here
	render();//normal render at (0,0)
	glPopMatrix();
}