#include "Tank.h"
#include "Renderable.h"

Tank::Tank(b2World* world)
{
	setWorld(world);

	b2Body* body;
	body = NULL;

	//set up dynamic body, store in class variable
	b2BodyDef myBodyDef;
	myBodyDef.type = b2_dynamicBody;
	myBodyDef.position.Set(50, 50);
	body = world->CreateBody(&myBodyDef);

	//add circle fixture
	b2Vec2 vertices[4];
	vertices[0].Set(1.0f, 2.0f);
	vertices[1].Set(3.0f, 1.0f);
	vertices[2].Set(-2.0f, -1.0f);
	vertices[3].Set(-1.5f, 1.0f);
	int32 verticesCount = 4;
	b2PolygonShape tankShape;
	tankShape.Set(vertices, verticesCount);

	b2FixtureDef myFixtureDef;
	myFixtureDef.shape = &tankShape;
	myFixtureDef.density = 1;
	body->CreateFixture(&myFixtureDef);
	setBody(body);
}


Tank::~Tank()
{
	getWorld()->DestroyBody(getBody());
}

void Tank::render() {
	b2Body* body = getBody();
	glColor3f(0, 0, 1);//blue

	/*
	Use GetVertexCount() and GetVertex() to get the vertices from a polygon shape.

	Note that vertex positions stored in the fixture are in body coordinates 
	(relative to the body that the fixture is attached to). 
	To get locations in world coordinates, you would have to multiply by the body transform:

	b2Vec2 worldPos = body->GetWorldPoint( localPos );
	*/

	b2Fixture* fixture;
	glBegin(GL_QUADS);
	//glPointSize(4);
	for (fixture = body->GetFixtureList(); fixture; fixture = fixture->GetNext())
	{
		b2Shape::Type shapeType = fixture->GetType();
		if (shapeType == b2Shape::e_polygon)
		{
			b2PolygonShape* polygonShape = (b2PolygonShape*)fixture->GetShape();
			int vertexCount = polygonShape->GetVertexCount();
			b2Vec2 vertex, vertexPositionInWorld;
			for (int i = 0; i < vertexCount; i++)
			{
				vertex = polygonShape->GetVertex(i);
				vertexPositionInWorld = body->GetWorldPoint(vertex);
				//glVertex2f(world->positionToPixel(vertexPositionInWorld.x), world->positionToPixel(vertexPositionInWorld.y));
			}
		}
	}

	glEnd();

	//circle outline
	/*glBegin(GL_LINE_LOOP);
	for (float a = 0; a < 360 * 3.1415f / 180; a += 30 * 3.1415f / 180)
		glVertex2f(sinf(a)*10.0f, cosf(a)*10.0f);
	glEnd();*/

	/*b2Vec2 vel = body->GetLinearVelocity();
	float red = vel.Length() / 20.0f;
	red = fmin(1.0f, red);
	glColor3f(red, 0.5, 0.5);*/
}
