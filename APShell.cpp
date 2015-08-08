#include "APShell.h"

 // Armour Piercing Shell

APShell::APShell(b2World* world, Config* config, Config::Players player, b2Vec2 position, float angle, int shellVelocity)
	: Shell(world, config, player, Config::ShellType::AP, position, angle, shellVelocity)
{
	b2Body* body = getBody();

	//add polygon fixture
	b2Vec2 vertices[4];
	vertices[0].Set(0.2f, 0.4f);
	vertices[1].Set(0.2f, -0.4f);
	vertices[2].Set(-0.2f, -0.4f);
	vertices[3].Set(-0.2f, 0.4f);
	int32 verticesCount = 4;
	b2PolygonShape APShellShape;
	APShellShape.Set(vertices, verticesCount);

	FixtureData* userData = new FixtureData;
	userData->fixtureType = Config::FixtureType::SHELL;
	userData->owner = player;

	b2FixtureDef myFixtureDef;
	myFixtureDef.shape = &APShellShape;
	myFixtureDef.density = 5.0;
	myFixtureDef.userData = (void*)userData;
	body->CreateFixture(&myFixtureDef);
}

APShell::~APShell()
{
}

void APShell::render()
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

			glColor3f(0.9f, 0.9f, 0.9f);//light gray
			glBegin(GL_QUADS);
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
