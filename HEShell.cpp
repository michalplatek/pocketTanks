#include "HEShell.h"
#include <math.h>
#include <GL\freeglut.h>

// High Explosive Shell

HEShell::HEShell(b2World* world, Config* config, Config::Players player, b2Vec2 position, float angle) : Shell(world, config, player, position, angle)
{
	b2Body* body = getBody();

	b2CircleShape HEShellShape;
	HEShellShape.m_p.Set(0.0f,0.0f);
	HEShellShape.m_radius = 1.0f;

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
			for (int i = 0; i < 360; i+=30){
				double angle = i*DEGTORAD;
				double x = getConfig()->positionToPixel(cos(angle)*radius);
				double y = getConfig()->positionToPixel(sin(angle)*radius);
				glVertex2d(x, y);
			}

			//b2Shape::Type shapeType = fixture->GetType();
			//if (shapeType == b2Shape::e_polygon)
			//{
			//	b2PolygonShape* polygonShape = (b2PolygonShape*)fixture->GetShape();
			//	int vertexCount = polygonShape->GetVertexCount();
			//	b2Vec2 vertex, vertexPositionInWorld;

			//	glColor3f(1.0f, 0.0f, 0.0f);//light gray
			//	glBegin(GL_QUADS);
			//	for (int i = 0; i < vertexCount; i++)
			//	{
			//		vertex = polygonShape->GetVertex(i);
			//		float posx = getConfig()->positionToPixel(vertex.x);
			//		float posy = getConfig()->positionToPixel(vertex.y);

			//		glVertex2f(posx, posy);
			//	}

			glEnd();
		}
	}
}