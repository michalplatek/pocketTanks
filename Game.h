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
#include "Particle.h"
#include <vector>

class Game
{
	Config* config;
	World* world;
	b2ContactListener* contactListener;
	std::vector<Tank*> tanks;
	std::vector<Shell*> shells;
	std::vector<Particle*> particles;
	int turnCounter;
	
	Config::Status status;

public:
	Game(Config* config);
	~Game();
	// perform an iteration of the world
	void step();
	
	World* getWorld();

	/* status and turn */
	Config::Status getStatus();
	void setStatus(Config::Status status);
	int getTurn();
	void nextTurn();
	bool isTurnOf(Config::Players player);
	Config::Players currentPlayer();
	
	/* tanks */
	Tank* getTank(int i);
	Tank* getTank(Config::Players player);
	
	/* shells and shots */
	Shell* getShell(int i);
	int numberOfShells();
	void removeShells();
	void removeShell(int i);
	void shoot(Config::Players player);
	void resolveCollisions();
};

#endif
