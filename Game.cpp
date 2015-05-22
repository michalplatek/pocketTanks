#include "Game.h"


Game::Game(Config* config)
{
	this->config = config;
	world = new World(config);

	/* creating tanks */
	tanks.push_back(new Tank(world->getWorld(), config, Config::Players::PLAYER_1));
	tanks.push_back(new Tank(world->getWorld(), config, Config::Players::PLAYER_2));

	status = Config::Status::RUNNING;
}


Game::~Game()
{
	for (int i = 0; i < config->NUM_TANKS; i++) {
		delete tanks[i];
	}
	delete world;
	tanks.clear();
}

void Game::step() 
{
	world->getWorld()->Step(
		config->BOX2D_TIME_STEP,
		config->BOX2D_VELOCITY_ITERATIONS,
		config->BOX2D_POSITION_ITERATIONS
	);
}

Config::Status Game::getStatus() 
{
	return status;
}

void Game::setStatus(Config::Status status) 
{
	this->status = status;
}

World* Game::getWorld() 
{
	return world;
}

Tank* Game::getTank(int i) 
{
	/* TODO? sprawdzi� czy i nie jest poza zakresem? Wyj�tek? */
	return tanks[i];
}