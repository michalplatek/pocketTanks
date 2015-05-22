#include "Game.h"


Game::Game(Config* config)
{
	this->config = config;
	world = new World(config);
	shell = nullptr;

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
	/* TODO? sprawdzic czy i nie jest poza zakresem? Wyjatek? */
	return tanks[i];
}

Tank* Game::getTank(Config::Players player)
{
	Tank* tankPtr = nullptr;
	b2Body* tankBody;
	for (int i = 0; i < config->NUM_PLAYERS; i++)
	{
		// TODO? sprawdzic czy UserData ustaione. Jesli nie, to wyjatek?
		tankPtr = getTank(i);
		tankBody = tankPtr->getBody();
		BodyData* bodyData = (BodyData*)tankBody->GetUserData();
		if (bodyData->owner == player)
		{
			return tankPtr;
		}
	}
	return nullptr;
}

void Game::shoot(Config::Players player)
{
	Tank* tank = getTank(player);
	if (tank != nullptr)
	{
		if (shell != nullptr)
		{
			delete shell;
		}
		switch (tank->getLoadedShellType())
		{
		case Config::ShellType::AP:
			shell = new APShell(world->getWorld(), config, tank->getBarrelEndPosition(), tank->getBarrelAngle());
			break;
		case Config::ShellType::HE:
			shell = new HEShell(world->getWorld(), config, tank->getBarrelEndPosition(), tank->getBarrelAngle());
			break;
		case Config::ShellType::SHRAPNEL:
			shell = new ShrapnelShell(world->getWorld(), config, tank->getBarrelEndPosition(), tank->getBarrelAngle());
			break;
		default:
			shell = new APShell(world->getWorld(), config, tank->getBarrelEndPosition(), tank->getBarrelAngle());
			break;
		}
	}
}