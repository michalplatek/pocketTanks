#include "Shell.h"
#include "Renderable.h"
#include "World.h"
#include "Tank.h"

Shell::Shell(b2World* world, Config* config, Config::Players player, Config::ShellType shellType, b2Vec2 position, float angle)
	: Renderable(config), shellType(shellType), explosion(nullptr)
{
	setWorld(world);

	b2Body* body = nullptr;

	BodyData* bodyData = new BodyData;
	bodyData->bodyType = Config::BodyType::SHELL;
	bodyData->owner = player;

	//set up dynamic body, store in class variable
	b2BodyDef myBodyDef;
	myBodyDef.type = b2_dynamicBody;
	myBodyDef.bullet = true;
	//start position -> position of barrel
	myBodyDef.position.Set(position.x, position.y);
	myBodyDef.angle = angle;
	myBodyDef.userData = (void*)bodyData;

	body = world->CreateBody(&myBodyDef);

	float vectorX = cos(angle * DEGTORAD);
	float vectorY = sin(angle * DEGTORAD);
	printf("cos(%f)= %f, sin(%f)= %f\n", angle, vectorX, angle, vectorY);
	//body->SetTransform(b2Vec2(position.x, position.y), angle);
	body->ApplyLinearImpulse(b2Vec2(-vectorX * config->SHELL_VELOCITY, vectorY * config->SHELL_VELOCITY), b2Vec2(0.0f, 0.0f), true);

	setBody(body);
}

bool Shell::collision()
{
	b2Body* body = getBody();
	for (b2ContactEdge* edge = body->GetContactList(); edge; edge = edge->next)
	{
		if (edge->contact->IsTouching())
		{
			return true;
		}
	}
	return false;
}

Shell::~Shell()
{
	if (explosion != nullptr)
	{
		getWorld()->DestroyBody(explosion);
	}
	if (getBody() != nullptr)
	{
		getWorld()->DestroyBody(getBody());
	}
}

void Shell::explode()
{
	b2Body* explosion = nullptr;
	//set up dynamic body, store in class variable
	b2BodyDef myBodyDef;
	myBodyDef.type = b2_staticBody;
	// last known position of the shell
	myBodyDef.position = getBody()->GetPosition();

	getWorld()->DestroyBody(getBody());

	explosion = getWorld()->CreateBody(&myBodyDef);

	b2CircleShape explosionShape;
	explosionShape.m_p.Set(0.0f, 0.0f);
	explosionShape.m_radius = getConfig()->EXPLOSION_RADIUS[shellType];

	b2FixtureDef myFixtureDef;
	myFixtureDef.shape = &explosionShape;
	myFixtureDef.density = 0;
	myFixtureDef.isSensor = true;
	explosion->CreateFixture(&myFixtureDef);

	setBody(explosion);
}

bool Shell::shouldBounce()
{
	return false;
}

void Shell::bounce()
{

}
