#include "Tank.h"

Tank::Tank(b2World* world, Config* config, Config::Players player): 
	Renderable(config),
	player(player), 
	loadedShellType(Config::ShellType::HE), 
	movementHorizontal(Config::Direction::NONE),
	movementVertical(Config::Direction::NONE)
{
	setWorld(world);

	b2Body* body;
	body = NULL;

	BodyData* bodyData = new BodyData;
	bodyData->bodyType = Config::BodyType::TANK;
	bodyData->owner = player;

	//set up dynamic body, store in class variable
	b2BodyDef myBodyDef;
	myBodyDef.type = b2_dynamicBody;
	myBodyDef.position.Set(config->START_POSITION_X[player], config->START_POSITION_Y[player]);
	myBodyDef.userData = (void*)bodyData;
	
	body = world->CreateBody(&myBodyDef);

	//add polygon fixture
	b2Vec2 vertices[4];
	vertices[0].Set(2.0, 1.5f);
	vertices[1].Set(3.0f, -1.0f);
	vertices[2].Set(-3.0f, -1.0f);
	vertices[3].Set(-2.5f, 1.5f);
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
}


Tank::~Tank()
{
	getWorld()->DestroyBody(getBody());
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
				
				//if (i == 0) printf("%f %f\n", posx, posy);

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
	b2Vec2 tankPosition = getBodyPosition();
	BodyData* userData = (BodyData*)getBody()->GetUserData();
	Config::Players player = userData->owner;
	float factor = player == Config::Players::PLAYER_1 ? 1.0f : -1.0f;
	return b2Vec2(tankPosition.x + factor * 3.0f, tankPosition.y + 3.0f);
}

float Tank::getBarrelAngle()
{
	b2Vec2 tankPosition = getBodyPosition();
	BodyData* userData = (BodyData*)getBody()->GetUserData();
	Config::Players player = userData->owner;
	float angle = player == Config::Players::PLAYER_1 ? 135.0f : 45.0f;
	return angle;
}

void Tank::setHorizontalDirection(Config::Direction direction)
{
	movementHorizontal = direction == Config::Direction::LEFT || direction == Config::Direction::RIGHT ? direction : Config::Direction::NONE;
}

void Tank::setVerticalDirection(Config::Direction direction)
{
	movementVertical = direction == Config::Direction::UP || direction == Config::Direction::DOWN ? direction : Config::Direction::NONE;
}

