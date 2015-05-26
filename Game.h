#ifndef _GAME_H_
#define _GAME_H_

#include "World.h"
#include "Tank.h"
#include "Shell.h"
#include "Config.h"
#include "Shell.h"
#include "APShell.h"
#include "HEShell.h"
#include "ShrapnelShell.h"
#include <vector>

class Game
{
	Config* config;
	World* world;
	std::vector<Tank*> tanks;
	Shell* shell;
	int turnCounter;
	
	Config::Status status;

public:
	Game(Config* config);
	~Game();
	// perform an iteration of the world
	void step();
	Config::Status getStatus();
	void setStatus(Config::Status status);
	int getTurn();
	void nextTurn();
	bool isTurnOf(Config::Players player);
	World* getWorld();
	Tank* getTank(int i);
	Tank* getTank(Config::Players player);
	Shell* getShell();
	bool shellExists();
	void removeShell();
	void shoot(Config::Players player);
};

#endif
