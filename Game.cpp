#include "Game.h"


Game::Game(Config* config) : turnCounter(1), config(config), status(Config::Status::RUNNING), shellVelocity(0)
{
	world = new World(config);
	/* creating tanks */
	tanks.push_back(new Tank(world->getWorld(), config, Config::Players::PLAYER_1));
	tanks.push_back(new Tank(world->getWorld(), config, Config::Players::PLAYER_2));
	//contactListener = new b2ContactListener();
	//world->getWorld()->SetContactListener(contactListener);

}


Game::~Game()
{
	for (unsigned int i = 0; i < tanks.size(); i++) {
		delete tanks[i];
	}
	for (unsigned int i = 0; i < shells.size(); i++) {
		delete shells[i];
	}
	for (unsigned int i = 0; i < particles.size(); i++) {
		delete particles[i];
	}
	delete world;
	tanks.clear();
	shells.clear();
	particles.clear();
}

void Game::step() 
{
	world->getWorld()->Step(
		config->BOX2D_TIME_STEP,
		config->BOX2D_VELOCITY_ITERATIONS,
		config->BOX2D_POSITION_ITERATIONS
	);
	if (numberOfShells())
	{
		resolveCollisions();
	}
}

void Game::resolveCollisions()
{
	for (unsigned int shell = 0; shell < shells.size(); shell++)
	{
		if (shells[shell]->collision())
		{
			Config::Players tankHit = shells[shell]->GetObjectCollision();

			if (tankHit == Config::Players::NONE)
			{
				// something was hit, but it wasn't a tank => the ground was hit!
				boom(shell);
			}
			else
			{
				// a tank was hit
				if (shells[shell]->shouldBounce())
				{
					shells[shell]->bounce();
				}
				else
				{
					
					if ((shells[shell]->getShellType()) == Config::ShellType::AP){
						tanks[tankHit]->healthPoints -= 20;
						
					}
					else if ((shells[shell]->getShellType()) == Config::ShellType::HE){
						tanks[tankHit]->healthPoints -= 30;
					}
					else {
						tanks[tankHit]->healthPoints -= 10;
					}

					if (tanks[tankHit]->healthPoints <= 0)
						this->setStatus(Config::Status::FINISHED);

					boom(shell);
				}
			}
			nextTurn();
		}
	}
}

void Game::boom(int shellIndex)
{
	shells[shellIndex]->explode();
	damageWorld(shells[shellIndex]);
	removeShell(shellIndex);
}

void Game::damageWorld(Shell* shell)
{
	shell->interactWith(destructibleBodies(
		shell->getBodyPosition(),
		config->EXPLOSION_RADIUS[shell->getShellType()]
	));
}

unordered_set<b2Body*> Game::destructibleBodies(b2Vec2 position, float radius)
{
	return world->getDestructibleBodies(position, radius);
}

Config::Status Game::getStatus() 
{
	return status;
}

void Game::setStatus(Config::Status status) 
{
	this->status = status;
}

int Game::getTurn()
{
	return turnCounter;
}

void Game::nextTurn()
{
	turnCounter++;
}

bool Game::isTurnOf(Config::Players player)
{
	if (turnCounter % 2 == 1)
	{
		return config->startingPlayer == Config::Players::PLAYER_1;
	}
	else
	{
		return !(config->startingPlayer == Config::Players::PLAYER_1);
	}
}

Config::Players Game::currentPlayer(){
	return isTurnOf(Config::Players::PLAYER_1) ? Config::Players::PLAYER_1 : Config::Players::PLAYER_2;

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

Shell* Game::getShell(int i)
{
	return shells[i];
}

int Game::numberOfShells()
{
	return shells.size();
}

void Game::removeShell(int i)
{
	delete shells[i];
	shells.erase(shells.begin() + i);
}

void Game::removeShells()
{
	while (shells.size() > 0)
	{
		removeShell(0);
	}
}

void Game::shoot(Config::Players player)
{
	Tank* tank = getTank(player);
	if (tank != nullptr)
	{
		tank->stop();

		if (numberOfShells() > 0)
		{
			return;
			/*removeShells();*/
		}
		switch (tank->getLoadedShellType())
		{
		case Config::ShellType::AP:
			shells.push_back(new APShell(world->getWorld(), config, player, tank->getBarrelEndPosition(), tank->getBarrelAngle(), shellVelocity));
			break;
		case Config::ShellType::HE:
			shells.push_back(new HEShell(world->getWorld(), config, player, tank->getBarrelEndPosition(), tank->getBarrelAngle(), shellVelocity));
			break;
		case Config::ShellType::SHRAPNEL:
			shells.push_back(new ShrapnelShell(world->getWorld(), config, player, tank->getBarrelEndPosition(), tank->getBarrelAngle(), shellVelocity));
			break;
		default:
			shells.push_back(new APShell(world->getWorld(), config, player, tank->getBarrelEndPosition(), tank->getBarrelAngle(), shellVelocity));
			break;
		}
	}
}