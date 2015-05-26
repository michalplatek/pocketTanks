#include "HEShell.h"
#include <math.h>

// High Explosive Shell

HEShell::HEShell(b2World* world, Config* config, Config::Players player, b2Vec2 position, float angle) : Shell(world, config, player, position, angle)
{
	b2Body* body = getBody();

	//add polygon fixture
	//b2Vec2 vertices[4];
	/*vertices[0].Set(0.1f, 0.2f);
	vertices[1].Set(0.1f, -0.2f);
	vertices[2].Set(-0.1f, -0.2f);
	vertices[3].Set(-0.1f, 0.2f);*/
	

	//int32 verticesCount = 4;
	b2CircleShape HEShellShape;
	HEShellShape.m_p.Set(0.0f,0.0f);
	HEShellShape.m_radius = 0.3f;

	FixtureData* userData = new FixtureData;
	userData->fixtureType = Config::FixtureType::SHELL;
	userData->owner = player;

	b2FixtureDef myFixtureDef;
	myFixtureDef.shape = &HEShellShape;
	myFixtureDef.density = 1.0f;
	myFixtureDef.userData = (void*)userData;
	body->CreateFixture(&myFixtureDef);

}

HEShell::~HEShell()
{

}

void HEShell::render()
{
	b2Body* body = getBody();
	b2Fixture* fixture;

	for (fixture = body->GetFixtureList(); fixture; fixture = fixture->GetNext())
	{
		b2Shape::Type shapeType = fixture->GetType();
		if (shapeType == b2Shape::e_circle)
		{
			b2CircleShape* circleShape = (b2CircleShape*)fixture->GetShape();
			int radius = circleShape->m_radius;

			glColor3f(0.9f, 0.9f, 0.9f);//light gray
			glBegin(GL_LINE_LOOP);
			for (int i = 0; i <= 360; i++){
				double angle = 2 * 3.14 * i / 360;
				double x = cos(angle)*radius;
				double y = sin(angle)*radius;
				glVertex2d(x, y);
			}
			glEnd();
		}
	}
}