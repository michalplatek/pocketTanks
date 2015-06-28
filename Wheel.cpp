#include "Wheel.h"
#include "Renderable.h"

Wheel::Wheel(b2World* world, Config* config, Config::Players player, float radius) : Renderable(config),radius(radius){


	b2Body* mbody;
	mbody = NULL;

	BodyData* bodyData = new BodyData;
	bodyData->bodyType = Config::BodyType::TANK;
	bodyData->owner = player;
	b2BodyDef myBodyDef;
	myBodyDef.type = b2_dynamicBody;
	b2Vec2 pos(config->START_POSITION_X[player], config->START_POSITION_Y[player]);
	myBodyDef.position.Set(pos.x, pos.y);
	myBodyDef.userData = (void*)bodyData;
	mbody = world->CreateBody(&myBodyDef);

	b2CircleShape wheelShape;
	wheelShape.m_p.Set(0, 0);
	wheelShape.m_radius = radius;

	FixtureData* userData = new FixtureData;
	userData->fixtureType = Config::FixtureType::TANK_WHEEL;
	userData->owner = player;

	b2FixtureDef myFixtureDef;
	myFixtureDef.shape = &wheelShape;
	myFixtureDef.density = 1;
	myFixtureDef.userData = (void*)userData;
	mbody->CreateFixture(&myFixtureDef);

	setBody(mbody);
}

void Wheel::rotate(float angle){

}


Wheel::~Wheel(){

	getWorld()->DestroyBody(getBody());
}
void Wheel::render(){

	b2Body* mbody = getBody();
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

			glColor3f(0.0f, 0.0f, 1.0f);
			glBegin(GL_POLYGON);
			for (int i = 0; i < 360; i += 30){
				float angle = i*DEGTORAD;
				if (i > 180) 
					glColor3f(1.0f, 0.0f, 0.0f);
				float x = getConfig()->positionToPixel(cos(angle)*(radius-0.05));
				float y = getConfig()->positionToPixel(sin(angle)*(radius - 0.05));
				glVertex2f(x, y);
			}
			glEnd();

			glColor3f(1.0f, 1.0f, 1.0f);
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