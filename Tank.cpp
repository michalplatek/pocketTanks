#include "Tank.h"
#include "Renderable.h"

Tank::Tank(b2World* world, Config* config, Config::Players player) : Renderable(config), player(player)
{
	setWorld(world);

	b2Body* body;
	body = NULL;

	//set up dynamic body, store in class variable
	b2BodyDef myBodyDef;
	myBodyDef.type = b2_dynamicBody;
	myBodyDef.position.Set(config->START_POSITION_X[player], config->START_POSITION_Y[player]);
	
	body = world->CreateBody(&myBodyDef);
	//getBody()->SetTransform(getBody()->GetPosition(), config->START_ROTATION[player]);

	//add circle fixture
	b2Vec2 vertices[4];
	vertices[0].Set(2.0, 1.5f);
	vertices[1].Set(3.0f, -1.0f);
	vertices[2].Set(-3.0f, -1.0f);
	vertices[3].Set(-2.5f, 1.5f);
	int32 verticesCount = 4;
	b2PolygonShape tankShape;
	tankShape.Set(vertices, verticesCount);

	ObjectData* objectData = new ObjectData;
	objectData->health = config->MAX_HEALTH;
	objectData->objectType = Config::Objects::TANK_FRONT;

	b2FixtureDef myFixtureDef;
	myFixtureDef.shape = &tankShape;
	myFixtureDef.density = 1;
	myFixtureDef.userData = (void*)objectData;
	body->CreateFixture(&myFixtureDef);
	setBody(body);
}


Tank::~Tank()
{
	getWorld()->DestroyBody(getBody());
}

void Tank::render() {
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

			glColor3f(1, 0, 1);//pink
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
