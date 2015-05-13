#include "Tank.h"

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
