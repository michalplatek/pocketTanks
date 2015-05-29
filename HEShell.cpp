#include "HEShell.h"
#include <math.h>
#include <GL\freeglut.h>

// High Explosive Shell

HEShell::HEShell(b2World* world, Config* config, Config::Players player, b2Vec2 position, float angle)
	: Shell(world, config, player, Config::ShellType::HE, position, angle)
{
	b2Body* body = getBody();

	b2CircleShape HEShellShape;
	HEShellShape.m_p.Set(0.0f,0.0f);
	HEShellShape.m_radius = 0.3f;

	FixtureData* userData = new FixtureData;
	userData->fixtureType = Config::FixtureType::SHELL;
	userData->owner = player;

	b2FixtureDef myFixtureDef;
	myFixtureDef.shape = &HEShellShape;
	myFixtureDef.density = 5.0f;
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
			float radius = circleShape->m_radius;

			glColor3f(0.9f, 0.9f, 0.9f);//light gray
			glBegin(GL_LINE_LOOP);
			for (int i = 0; i < 360; i+=30){
				float angle = i*DEGTORAD;
				float x = getConfig()->positionToPixel(cos(angle)*radius);
				float y = getConfig()->positionToPixel(sin(angle)*radius);
				glVertex2f(x, y);
			}
			glEnd();
		}
	}
}
