#include "Tank.h"
#include "Renderable.h"

Tank::Tank(World* world)
{
	float radius = 1;
	body = NULL;
	//set up dynamic body, store in class variable
	b2BodyDef myBodyDef;
	myBodyDef.type = b2_dynamicBody;
	myBodyDef.position.Set(0, 1);
	body = world->CreateBody(&myBodyDef);

	//add circle fixture
	b2CircleShape circleShape;
	circleShape.m_p.Set(0, 0);
	circleShape.m_radius = radius; //use class variable
	b2FixtureDef myFixtureDef;
	myFixtureDef.shape = &circleShape;
	myFixtureDef.density = 1;
	body->CreateFixture(&myFixtureDef);
}


Tank::~Tank()
{
	
}

void Tank::render() {
	glColor3f(1, 1, 1);//white

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
	red = fmin(1, red);
	glColor3f(red, 0.5, 0.5);
}

void Tank::renderAtBodyPosition()
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