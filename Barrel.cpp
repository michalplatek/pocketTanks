#include "Barrel.h"
#include "Renderable.h"



Barrel::Barrel(b2World* world, Config* config, Config::Players player) :
	Renderable(config)
{
	setWorld(world);

	b2Body* body;
	body = NULL;



	b2Body* mbody;
	mbody = NULL;

	BodyData* bodyData = new BodyData;
	bodyData->bodyType = Config::BodyType::TANK;
	bodyData->owner = player;
	b2BodyDef myBodyDef;
	myBodyDef.type = b2_dynamicBody;
	b2Vec2 pos(config->START_POSITION_X[player], config->START_POSITION_Y[player]);
	myBodyDef.position.Set(pos.x+1, pos.y+2);
	myBodyDef.userData = (void*)bodyData;
	mbody = world->CreateBody(&myBodyDef);

	b2Vec2 vertices2[4];
	vertices2[0].Set(0.0f, 0.5f);
	vertices2[1].Set(4.0f, 0.5f);
	vertices2[2].Set(4.0f, -0.5f);
	vertices2[3].Set(0.0f, -0.5f);
	int32 verticesCount2 = 4;
	b2PolygonShape barrelShape;
	barrelShape.Set(vertices2, verticesCount2);

	FixtureData* userData = new FixtureData;
	userData->fixtureType = Config::FixtureType::TANK_BARREL;
	userData->owner = player;

	b2FixtureDef myFixtureDef;
	myFixtureDef.shape = &barrelShape;
	myFixtureDef.density = 0;
	myFixtureDef.userData = (void*)userData;
	mbody->CreateFixture(&myFixtureDef);

	setBody(mbody);


}


Barrel::~Barrel()
{
	getWorld()->DestroyBody(getBody());
}

void Barrel::rotate(float angle){
	printf("angle: %f \n", body->GetAngle());
	
	if (body->GetAngle() + angle*DEGTORAD <= 90 * DEGTORAD && body->GetAngle() + angle*DEGTORAD >= -0.1 * DEGTORAD)
		body->SetTransform(body->GetPosition(), body->GetAngle() + angle*DEGTORAD);

}



void Barrel::render() {
	b2Body* mbody = getBody();
	b2Fixture* fixture;

	

	for (fixture = mbody->GetFixtureList(); fixture; fixture = fixture->GetNext())
	{
		b2Shape::Type shapeType = fixture->GetType();
		if (shapeType == b2Shape::e_polygon)
		{
			//printf("barrelbody: %f %f \n", mbody->GetPosition().x, mbody->GetPosition().y);
			b2PolygonShape* polygonShape = (b2PolygonShape*)fixture->GetShape();

			int vertexCount = polygonShape->GetVertexCount();

			b2Vec2 vertex, vertexPositionInWorld;

			glColor3f(1, 1, 0);
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
	}

	

	

}

b2Vec2 Barrel::getBarrelEndPosition()
{
	b2Vec2 barrelPosition = getBodyPosition();
	BodyData* userData = (BodyData*)getBody()->GetUserData();
	Config::Players player = userData->owner;
	float factor = player == Config::Players::PLAYER_1 ? 1.0f : -1.0f;
	return b2Vec2(barrelPosition.x + factor * 3.0f, barrelPosition.y + 3.0f);

	
}

float Barrel::getBarrelAngle()
{
	/*b2Vec2 tankPosition = getBodyPosition();
	BodyData* userData = (BodyData*)getBody()->GetUserData();
	Config::Players player = userData->owner;
	float angle = player == Config::Players::PLAYER_1 ? 135.0f : 45.0f;*/
	return BarrelAngle;
}