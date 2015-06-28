#include "Tank.h"
#include "Renderable.h"

Tank::Tank(b2World* world, Config* config, Config::Players player) :
Renderable(config),
player(player),
loadedShellType(Config::ShellType::HE),
movementVertical(Config::Direction::NONE)
{
	setWorld(world);

	movementHorizontal = player == Config::Players::PLAYER_2 ? Config::Direction::LEFT : Config::Direction::RIGHT;
	int direction = movementHorizontal == Config::Direction::LEFT ? -1 : 1;

	b2Body* body;
	body = NULL;

	BodyData* bodyData = new BodyData;
	bodyData->bodyType = Config::BodyType::TANK;
	bodyData->owner = player;

	//set up dynamic body, store in class variable
	b2BodyDef myBodyDef;
	myBodyDef.type = b2_dynamicBody;
	b2Vec2 pos(config->START_POSITION_X[player], config->START_POSITION_Y[player]);
	myBodyDef.position.Set(pos.x, pos.y);
	myBodyDef.userData = (void*)bodyData;

	body = world->CreateBody(&myBodyDef);

	//add polygon fixture
	b2Vec2 vertices[4];
	vertices[0].Set(direction * 2.0, 1.5f);
	vertices[1].Set(direction * 3.0f, -1.0f);
	vertices[2].Set(direction * -2.5f, -1.0f);
	vertices[3].Set(direction * -2.5f, 1.5f);
	int32 verticesCount = 4;
	b2PolygonShape tankShape;
	tankShape.Set(vertices, verticesCount);

	FixtureData* userData = new FixtureData;
	userData->fixtureType = Config::FixtureType::TANK_FRONT;
	userData->owner = player;

	b2FixtureDef myFixtureDef;
	myFixtureDef.shape = &tankShape;
	myFixtureDef.density = 1;
	myFixtureDef.userData = (void*)userData;
	body->CreateFixture(&myFixtureDef);
	setBody(body);

	GenerateBarrel(0.0f, pos, direction);


}


Tank::~Tank()
{
	getWorld()->DestroyBody(getBody());
}


void Tank::GenerateBarrel(float radius, b2Vec2 pos, int direction){



	Barrel *bar = new Barrel(world, config, player, movementHorizontal);

	barrel = bar;

	b2RevoluteJointDef jointDef;
	jointDef.bodyA = body;
	jointDef.localAnchorA.Set(direction * 1, 0.8f);
	jointDef.bodyB = bar->getBody();
	jointDef.localAnchorB.Set(0, 0);
	b2RevoluteJoint* joint = (b2RevoluteJoint*)world->CreateJoint(&jointDef);
	joints.push_back(joint);

}


void Tank::GenerateWheel(float radius, b2Vec2 pos){

	// TO DO

	/*b2Body* mbody;
	mbody = NULL;

	BodyData* bodyData = new BodyData;
	bodyData->bodyType = Config::BodyType::TANK;
	bodyData->owner = player;
	b2BodyDef myBodyDef;
	myBodyDef.type = b2_dynamicBody;
	myBodyDef.position.Set(pos.x, pos.y);
	myBodyDef.userData = (void*)bodyData;
	mbody = world->CreateBody(&myBodyDef);

	b2CircleShape wheelShape;
	wheelShape.m_p.Set(pos.x, pos.y);
	wheelShape.m_radius = radius;

	FixtureData* userData = new FixtureData;
	userData->fixtureType = Config::FixtureType::TANK_WHEEL;
	userData->owner = player;

	b2FixtureDef myFixtureDef;
	myFixtureDef.shape = &wheelShape;
	myFixtureDef.density = 1;
	myFixtureDef.userData = (void*)userData;
	mbody->CreateFixture(&myFixtureDef);

	wheels.push_back(mbody);

	b2RevoluteJointDef jointDef;
	jointDef.bodyA = body;
	jointDef.localAnchorA = b2Vec2(2, 2);
	jointDef.bodyB = mbody;
	b2RevoluteJoint* joint = (b2RevoluteJoint*)world->CreateJoint(&jointDef);
	joints.push_back(joint);*/
}

void Tank::render() {
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

			glColor3f(1, 0, 1);//pink
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

Config::ShellType Tank::getLoadedShellType()
{
	return loadedShellType;
}

void Tank::setLoadedShellType(Config::ShellType shellType)
{
	loadedShellType = shellType;
}

b2Vec2 Tank::getBarrelEndPosition()
{
	

	

	return barrel->getBarrelEndPosition();
}

float Tank::getBarrelAngle()
{
	return barrel->getBarrelAngle();
}

Config::Direction Tank::getHorizontalDorection(){

	return movementHorizontal;
	
}

void Tank::setHorizontalDirection(Config::Direction direction)
{
	movementHorizontal = direction == Config::Direction::LEFT || direction == Config::Direction::RIGHT ? direction : Config::Direction::NONE;
}

void Tank::setVerticalDirection(Config::Direction direction)
{
	movementVertical = direction == Config::Direction::UP || direction == Config::Direction::DOWN ? direction : Config::Direction::NONE;

	if (direction == Config::Direction::UP)
		barrel->rotate(1);
	else if (direction == Config::Direction::DOWN)
		barrel->rotate(-1);

}

