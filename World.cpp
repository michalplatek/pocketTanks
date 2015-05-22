#include<GL/freeglut.h>
#include "World.h"


World::World(Config* config) : Renderable(config)
{
	b2World* world = new b2World(b2Vec2(0.0f, config->GRAVITY));
	setWorld(world);

	b2Body* body = NULL;

	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(100.0f, 10.0f);
	body = world->CreateBody(&bodyDef);

	b2Vec2 vertices[4];
	vertices[0].Set(-100.0, 5.0f);
	vertices[1].Set(100.0, 5.0f);
	vertices[2].Set(100.0, -5.0f);
	vertices[3].Set(-100.0, -5.0f);
	int32 verticesCount = 4;
	b2PolygonShape worldShape;
	worldShape.Set(vertices, verticesCount);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &worldShape;
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

	/*
	Use GetVertexCount() and GetVertex() to get the vertices from a polygon shape.

	Note that vertex positions stored in the fixture are in body coordinates
	(relative to the body that the fixture is attached to).
	To get locations in world coordinates, you would have to multiply by the body transform:

	b2Vec2 worldPos = body->GetWorldPoint( localPos );
	*/

	b2Fixture* fixture;

	for (fixture = body->GetFixtureList(); fixture; fixture = fixture->GetNext())
	{
		b2Shape::Type shapeType = fixture->GetType();
		if (shapeType == b2Shape::e_polygon)
		{
			b2PolygonShape* polygonShape = (b2PolygonShape*)fixture->GetShape();
			int vertexCount = polygonShape->GetVertexCount();
			b2Vec2 vertex, vertexPositionInWorld;

			glColor3f(0.1f, 1.0f, 0.0f);//green
			glBegin(GL_QUADS);
			for (int i = 0; i < vertexCount; i++)
			{
				vertex = polygonShape->GetVertex(i);
				float posx = getConfig()->positionToPixel(vertex.x);
				float posy = getConfig()->positionToPixel(vertex.y);

				if (i == 0) printf("%f %f\n", posx, posy);

				glVertex2f(posx, posy);

			}
			glEnd();
		}
	}
}


