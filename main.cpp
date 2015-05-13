#include <Box2D/Box2D.h>
#include <boost/geometry.hpp>
#include <iostream>
#include "Game.h"
#include "Controller.h"
#include "View.h"
#include "Config.h"
using namespace std;

<<<<<<< HEAD
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
=======
int main() {
	cout << "Hello !";
	cout << "Moje zmiany sa wazniejsze!";
	cout << "Nie bo moje!";
>>>>>>> origin/master
	return 0;
}

