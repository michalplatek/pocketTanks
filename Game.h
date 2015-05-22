#ifndef _GAME_H_
#define _GAME_H_

#include "World.h"
#include "Tank.h"
#include "Shell.h"
#include "Config.h"
#include <vector>

class Game
{
	Config* config;
	World* world;
	std::vector<Tank*> tanks;
	Shell* shell;
	
	Config::Status status;

public:
	Game(Config* config);
	~Game();
	// perform an iteration of the world
	void step();
	Config::Status getStatus();

	void setStatus(Config::Status status);
	World* getWorld();
	Tank* getTank(int i);
};

#endif