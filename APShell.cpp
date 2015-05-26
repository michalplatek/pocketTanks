#include "APShell.h"

 // Armour Piercing Shell

APShell::APShell(b2World* world, Config* config, Config::Players player, b2Vec2 position, float angle) : Shell(world, config, player, position, angle)
{
	b2Body* body = getBody();

	//add polygon fixture
	b2Vec2 vertices[4];
	vertices[0].Set(0.1f, 0.4f);
	vertices[1].Set(0.1f, -0.4f);
	vertices[2].Set(-0.1f, -0.4f);
	vertices[3].Set(-0.1f, 0.4f);
	int32 verticesCount = 4;
	b2PolygonShape APShellShape;
	APShellShape.Set(vertices, verticesCount);

	FixtureData* userData = new FixtureData;
	userData->fixtureType = Config::FixtureType::SHELL;
	userData->owner = player;

	b2FixtureDef myFixtureDef;
	myFixtureDef.shape = &APShellShape;
	myFixtureDef.density = 1.0f;
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
	}
}

void APShell::explode()
{

}
