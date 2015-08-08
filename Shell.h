#ifndef _SHELL_H_
#define _SHELL_H_

#include "Renderable.h"
#include "World.h"
#include "Geometry.h"

class Shell : public Renderable
{
	Config::ShellType shellType;
	ring_t explosion;

public:
	Shell(b2World* world, Config* config, Config::Players player, Config::ShellType shellType, b2Vec2 position, float angle, int shellVelocity);
	virtual ~Shell();

	Config::ShellType getShellType();
	bool collision();
	Config::Players GetObjectCollision();
	bool shouldBounce();
	void bounce();
	void explode();
	void interactWith(unordered_set<b2Body*> destructibleBodies);
	template<typename It> std::vector<match_t> matchBodiesToRings(It begin, It end);

	virtual void render() = 0;
};

#endif
