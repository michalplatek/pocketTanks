#ifndef _SHELL_H_
#define _SHELL_H_

#include "Renderable.h"
#include "World.h"

class Shell : public Renderable
{
	Config::ShellType shellType;
public:
	Shell(b2World* world, Config* config, Config::Players player, Config::ShellType shellType, b2Vec2 position, float angle);
	virtual ~Shell();

	b2Body* explosion;
	bool collision();
	bool shouldBounce();
	void bounce();
	void explode();

	virtual void render() = 0;
};

#endif
