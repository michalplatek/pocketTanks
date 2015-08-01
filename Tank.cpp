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
	vertices[0].Set(direction * 2.0, 2.0f);
	vertices[1].Set(direction * 4.5f, -1.0f);
	vertices[2].Set(direction * -4.5f, -1.0f);
	vertices[3].Set(direction * -2.5f, 2.0f);
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
	GenerateWheel(1.0, pos, b2Vec2(-3, -1));
	GenerateWheel(1.0, pos, b2Vec2(-1, -1));
	GenerateWheel(1.0, pos, b2Vec2( 1, -1));
	GenerateWheel(1.0, pos, b2Vec2( 3, -1));

	healthPoints = 100;
	color = config->PLAYERC_COLOR[player];

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
	jointDef.enableMotor = true;
	jointDef.maxMotorTorque = 20;
	jointDef.motorSpeed = 360 * DEGTORAD; //1 turn per second counter-clockwise
	b2RevoluteJoint* joint = (b2RevoluteJoint*)world->CreateJoint(&jointDef);
	joints.push_back(joint);

}


void Tank::GenerateWheel(float radius, b2Vec2 pos, b2Vec2 anchor){

	// TO DO

	Wheel* wheel = new Wheel(world, config, player, radius);

	wheels.push_back(wheel);

	b2RevoluteJointDef jointDef;
	jointDef.bodyA = body;
	jointDef.localAnchorA = anchor;
	jointDef.bodyB = wheel->getBody();
	jointDef.localAnchorB.Set(0, 0);
	b2RevoluteJoint* joint = (b2RevoluteJoint*)world->CreateJoint(&jointDef);
	joints.push_back(joint);
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

			glColor3f(color.x,color.y,color.z);
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


void Tank::stop()
{
	body->SetLinearVelocity(b2Vec2(0.0f, 0.0f));
}


void Tank::setHorizontalDirection(Config::Direction direction)
{
	float MAX_SPEED = 3.5;

	movementHorizontal = direction == Config::Direction::LEFT || direction == Config::Direction::RIGHT ? direction : Config::Direction::NONE;
	printf("v: %f", body->GetLinearVelocity().x);

	if (direction == Config::Direction::LEFT){
		if (body->GetLinearVelocity().x > -MAX_SPEED)
			//body->ApplyForce(b2Vec2(-50.0f, 0.0f), body->GetWorldCenter(), true);
			body->ApplyLinearImpulse(b2Vec2(-20.0f, 0.0f), body->GetWorldCenter(), true);
	}
	else if (direction == Config::Direction::RIGHT){
		if (body->GetLinearVelocity().x < MAX_SPEED)
			//body->ApplyForce(b2Vec2(50.0f, 0.0f), body->GetWorldCenter(), true);
			body->ApplyLinearImpulse(b2Vec2(20.0f, 0.0f), body->GetWorldCenter(), true);
	}

}

void Tank::setVerticalDirection(Config::Direction direction)
{
	movementVertical = direction == Config::Direction::UP || direction == Config::Direction::DOWN ? direction : Config::Direction::NONE;

	if (direction == Config::Direction::UP)
		barrel->rotate(1);
	else if (direction == Config::Direction::DOWN)
		barrel->rotate(-1);

}

