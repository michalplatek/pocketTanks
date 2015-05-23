#include "ShrapnelShell.h"

	// Shrapnel Shell

ShrapnelShell::ShrapnelShell(b2World* world, Config* config, Config::Players player, b2Vec2 position, float angle) : Shell(world, config, player, position, angle)
{

}

ShrapnelShell::~ShrapnelShell()
{

}

void ShrapnelShell::render()
{
	b2Body* body = getBody();
}
