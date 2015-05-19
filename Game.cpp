#include "Game.h"


Game::Game(Config* config)
{
	this->config = config;
	world = new World(config);

	/* creating tanks */
	for (int i = 0; i < config->NUM_TANKS; i++) {
		tanks.push_back(new Tank(world->getWorld()));
	}
	status = Config::Status::RUNNING;
}


Game::~Game()
{
	delete world;
	for (int i = 0; i < config->NUM_TANKS; i++) {
		delete tanks[i];
	}
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
	/* TODO? sprawdziæ czy i nie jest poza zakresem? Wyj¹tek? */
	return tanks[i];
}