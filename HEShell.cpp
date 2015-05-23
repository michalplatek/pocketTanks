#include "HEShell.h"

// High Explosive Shell

HEShell::HEShell(b2World* world, Config* config, Config::Players player, b2Vec2 position, float angle) : Shell(world, config, player, position, angle)
{

}

HEShell::~HEShell()
{

}

void HEShell::render()
{
	b2Body* body = getBody();
}