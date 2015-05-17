#include <Box2D/Box2D.h>
#include <boost/geometry.hpp>
#include <iostream>
#include "Game.h"
#include "Controller.h"
#include "View.h"
#include "Config.h"
using namespace std;

int main(int argc, char** argv)
{
	Config* config = new Config(argc, argv);
	Controller* controller = new Controller(config);
	Game* pocketTanks = new Game(config);
	
	// Let's play Pocket Tanks!
	controller->play(pocketTanks);
	
	delete config;
	delete pocketTanks;
	delete controller;
	return 0;
}

	/*
	* Uwagi:
	*/