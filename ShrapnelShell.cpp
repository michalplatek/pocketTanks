#include "ShrapnelShell.h"
#include <GL\freeglut.h>

	// Shrapnel Shell

ShrapnelShell::ShrapnelShell(b2World* world, Config* config, Config::Players player, b2Vec2 position, float angle, int shellVelocity)
	: Shell(world, config, player, Config::ShellType::SHRAPNEL, position, angle, shellVelocity)
{
	b2Body* body = getBody();

	b2Vec2 vertices[8];

	vertices[0].Set(0.0f, 0.4f);
	vertices[1].Set(0.25f, 0.25f);

	vertices[2].Set(0.4f, 0.0f);
	vertices[3].Set(0.25f, -0.25f);

	vertices[4].Set(0.0f, -0.4f);
	vertices[5].Set(-0.25f, -0.25f);

	vertices[6].Set(-0.4f, 0.0f);
	vertices[7].Set(-0.25f, 0.25f);

	int32 verticesCount = 8;
	b2PolygonShape ShrapnelShape;
	ShrapnelShape.Set(vertices, verticesCount);

	FixtureData* userData = new FixtureData;
	userData->fixtureType = Config::FixtureType::SHELL;
	userData->owner = player;

	b2FixtureDef myFixtureDef;
	myFixtureDef.shape = &ShrapnelShape;
	myFixtureDef.density = 1.0f;
	myFixtureDef.userData = (void*)userData;
	body->CreateFixture(&myFixtureDef);

}

ShrapnelShell::~ShrapnelShell()
{

}

void ShrapnelShell::render()
{
	b2Body* body = getBody();
	b2Fixture* fixture;

	for (fixture = body->GetFixtureList(); fixture; fixture = fixture->GetNext())
	{
		b2Shape::Type shapeType = fixture->GetType();
		if (shapeType == b2Shape::e_polygon)
		{
			b2PolygonShape* polygonShape = (b2PolygonShape*)fixture->GetShape();
			int vertexCount = polygonShape->GetVertexCount();
			b2Vec2 vertex, vertexPositionInWorld;

			glColor3f(0.0f, 0.5f, 0.8f);
			glBegin(GL_POLYGON);
			for (int i = 0; i < vertexCount; i++)
			{
				vertex = polygonShape->GetVertex(i);
				float posx = getConfig()->positionToPixel(vertex.x);
				float posy = getConfig()->positionToPixel(vertex.y);

				glVertex2f(posx, posy);
			}
			glEnd();

			glBegin(GL_POLYGON);
			for (int i = 0; i < vertexCount; i++)
			{
				vertex = polygonShape->GetVertex(i);
				float posx = getConfig()->positionToPixel(vertex.x);
				float posy = getConfig()->positionToPixel(vertex.y);

				glVertex2f(posx, posy);
			}
			glEnd();

			glBegin(GL_POLYGON);
			for (int i = 0; i < vertexCount; i++)
			{
				vertex = polygonShape->GetVertex(i);
				float posx = getConfig()->positionToPixel(vertex.x);
				float posy = getConfig()->positionToPixel(vertex.y);

				glVertex2f(posx, posy);
			}
			glEnd();
		}
		else if (shapeType == b2Shape::e_circle)
		{
			b2CircleShape* circleShape = (b2CircleShape*)fixture->GetShape();
			float radius = circleShape->m_radius;

			glColor3f(0.9f, 0.9f, 0.9f);//light gray
			glBegin(GL_LINE_LOOP);
			for (int i = 0; i < 360; i += 30){
				float angle = i*DEGTORAD;
				float x = getConfig()->positionToPixel(cos(angle)*radius);
				float y = getConfig()->positionToPixel(sin(angle)*radius);
				glVertex2f(x, y);
			}
			glEnd();
		}
	}
}
