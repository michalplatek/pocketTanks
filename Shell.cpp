#include "Shell.h"
#include "Renderable.h"
#include "World.h"
#include "Tank.h"
#include "Geometry.h"

Shell::Shell(b2World* world, Config* config, Config::Players player, Config::ShellType shellType, b2Vec2 position, float angle, int shellVelocity)
	: Renderable(config), shellType(shellType)
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

	float vectorX = cos(angle);
	float vectorY = sin(angle);
	printf("cos(%f)= %f, sin(%f)= %f\n", angle, vectorX, angle, vectorY);
	//body->SetTransform(b2Vec2(position.x, position.y), angle);
	body->ApplyLinearImpulse(b2Vec2(vectorX * shellVelocity, vectorY * shellVelocity), b2Vec2(0.0f, 0.0f), true);

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

// goes through a set of bodies and returns a vector of pairs.
// each pair in the vector consists of:
//    - a body from the source set 
//    - a corresponding ring shape
template<typename It>
vector<match_t> Shell::matchBodiesToRings(It begin, It end)
{
	std::vector<match_t> batch;

	std::transform(begin, end, std::back_inserter(batch), [](b2Body* body)
	{
		auto f = body->GetFixtureList();
		auto shape = static_cast<b2ChainShape*>(f->GetShape());
		return std::make_pair(body, Geometry::convertShape(body->GetWorldCenter(), shape));
	});

	return batch;
}

Config::Players Shell::GetObjectCollision()
{
	b2Body* body = getBody();
	for (b2ContactEdge* edge = body->GetContactList(); edge; edge = edge->next)
	{
		if (edge->contact->IsTouching())
		{

			b2Body* colBody = edge->contact->GetFixtureA()->GetBody();
			if (colBody->GetUserData())
			{

				if (static_cast<_FixtureData*>(colBody->GetUserData())->owner == config->PLAYER_1)
				{
					FixtureData* userData = static_cast<_FixtureData*>(colBody->GetUserData());
					int life = userData->healthPoints;
					life = 0;
					return Config::Players::PLAYER_1;
				}
				else if (static_cast<_FixtureData*>(colBody->GetUserData())->owner == config->PLAYER_2)
				{
					return Config::Players::PLAYER_2;
				}
				else
				{
					return Config::Players::NONE;
				}

				//static_cast<Ball*>(bodyUserData)->startContact();
			}
			
		}
	}
	return Config::Players::NONE;
}


Shell::~Shell()
{
	if (getBody() != nullptr)
	{
		getWorld()->DestroyBody(getBody());
	}
}

void Shell::explode()
{
	b2Vec2 shellPosition = this->getBodyPosition();
	float explosionRadius = config->EXPLOSION_RADIUS[this->shellType];
	int explosionVerticies = config->EXPLOSION_VERTICIES;

	// create the explosion circle as ring_t and correct it
	explosion = Geometry::makeConvexRing(shellPosition, explosionRadius, explosionVerticies);
	bg::correct(explosion);
}

void Shell::interactWith(unordered_set<b2Body*> destructibleBodies)
{
	// pair each destructible body with a ring
	vector<match_t> shapes = matchBodiesToRings(destructibleBodies.begin(), destructibleBodies.end());

	// divide the set into 2 groups: larger and smaller
	// large shapes will be processed
	// small shapes will be destroyed
	auto divider = partition(shapes.begin(), shapes.end(), [](const match_t& m) {
		const double areaEpsilon = 0.02;
		return bg::area(m.second) > areaEpsilon;
	});

	// Remove small shapes
	for_each(divider, shapes.end(), [&](const match_t& m) {
		world->DestroyBody(m.first);
	});

	// Subtract the explosion shape from each destructible shape
	typedef pair<unique_ptr<b2ChainShape>, b2Filter> shape_property_t;
	vector<shape_property_t> resultShapes;
	for_each(shapes.begin(), divider, [&](const match_t& m) {
		ring_collection_t subtractionResult = Geometry::subtract(m.second, explosion);
		// Simplify the results
		if (config->SIMPLIFY_GEOMETRY)
		{
			Geometry::simplify(subtractionResult);
		}

		// Convert the rings to b2ChainShapes
		vector<unique_ptr<b2ChainShape>> converted = Geometry::convertGeometry(subtractionResult);

		// add the converted subtraction results to the result set
		auto moveBegin = make_move_iterator(converted.begin());
		auto moveEnd = make_move_iterator(converted.end());
		transform(moveBegin, moveEnd, back_inserter(resultShapes),
			[&](unique_ptr<b2ChainShape> converted) {
			const b2Filter& filter = m.first->GetFixtureList()->GetFilterData();
			return make_pair(move(converted), filter);
		});

		// destroy the destructible body if empty
		if (!subtractionResult.empty())
		{
			world->DestroyBody(m.first);
		}
	});

	// create bodies from the result shapes
	for (auto&& s : resultShapes)
	{
		b2BodyDef bodyDefinition;
		b2Body* body = world->CreateBody(&bodyDefinition);
		auto fixture = body->CreateFixture(s.first.get(), 0.0f);
		fixture->SetFilterData(s.second);
	}
}

bool Shell::shouldBounce()
{
	// shells never bounce at the moment
	// TODO : check the angle between the shell and the surface (normal vector of the surface).
	// IMPORANT: High Explosive (HE) Shells DO NOT bounce!
	return false;
}

void Shell::bounce()
{
	// TODO: change the direction of the shell's movement
}

Config::ShellType Shell::getShellType()
{
	return shellType;
}