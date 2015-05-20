#include "Shell.h"
#include "Renderable.h"
#include "World.h"

Shell::Shell(b2World* world, Config* config) : Renderable(config)
{
	setWorld(world);
}


Shell::~Shell()
{
}

void Shell::render()
{

}