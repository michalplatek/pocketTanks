#include "World.h"
using namespace boost::geometry;

World::World(Config* config) : Renderable(config)
{
	b2World* world = new b2World(b2Vec2(0.0f, config->GRAVITY));
	setWorld(world);

	b2Body* body = NULL;
	ring_t ring;
	
	BodyData* bodyData = new BodyData;
	bodyData->bodyType = Config::BodyType::WORLD;
	bodyData->owner = Config::Players::NONE;

	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(100.0f, 10.0f);
	bodyDef.userData = (void*)bodyData;
	body = world->CreateBody(&bodyDef);

	// Add a destructible polygon
	std::vector<b2Vec2> vertices = {
		b2Vec2{ -500.0f, 25.0f },
		b2Vec2{ 500.0f, 25.0f },
		b2Vec2{ 500.0f, 10.0f },
		b2Vec2{ -500.0f, 10.0f } 
	};

	auto worldShape = makeChain(vertices.data(), vertices.size(), true);

	FixtureData* userData = new FixtureData;
	userData->fixtureType = Config::FixtureType::WORLD;
	userData->owner = Config::Players::NONE;

	b2FixtureDef fixtureDef;
	fixtureDef.shape = worldShape.get();
	fixtureDef.density = 0.0f;
	fixtureDef.friction = 0.3f;
	fixtureDef.userData = (void*)userData;

	body->CreateFixture(&fixtureDef);
	setBody(body);
}

std::unique_ptr<b2ChainShape> World::makeChain(b2Vec2* points, int count, bool closed)
{
	std::unique_ptr<b2ChainShape> shape{ new b2ChainShape() };
	if (closed)
	{
		shape->CreateLoop(points, count);
	}
	else
	{
		shape->CreateChain(points, count);
	}
	return shape;
}

World::~World()
{
	b2World* world = getWorld();
	world->DestroyBody(getBody());
	//delete contactListener;
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
			printf("a polygon\n");
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

				//if (i == 0) printf("%f %f\n", posx, posy);

				glVertex2f(posx, posy);

			}
			glEnd();
		}
		else if (shapeType == b2Shape::e_chain)
		{
			b2ChainShape* chainShape = (b2ChainShape*)fixture->GetShape();
			int edgeCount = chainShape->GetChildCount();
			b2Vec2 vertex, vertexPositionInWorld;

			glColor3f(0.1f, 1.0f, 0.0f);//green
			glBegin(GL_QUADS);
			for (int i = 0; i < edgeCount; i++)
			{
				b2EdgeShape edge;
				chainShape->GetChildEdge(&edge, i);
				vertex = edge.m_vertex1;
				float posx = getConfig()->positionToPixel(vertex.x);
				float posy = getConfig()->positionToPixel(vertex.y);

				//if (i == 0) printf("%f %f\n", posx, posy);

				glVertex2f(posx, posy);

			}
			glEnd();
		}
	}
}


