#include <Box2D/Box2D.h>
//#include <boost/geometry.hpp>
#include <iostream>
#include "Game.h"
#include "Controller.h"
#include "View.h"
#include "Config.h"
using namespace std;

int main(int argc, char** argv)
{
	srand(time(NULL));
	Config config(argc, argv);
	Controller controller(&config);
	Game pocketTanks(&config);
	
	// Let's play Pocket Tanks!
	controller.play(&pocketTanks);

	return 0;
}

	/*
	* Uwagi:
	* nie alokowac pamieci dla b2Body, b2Fixture ani b2Joint!
	* uzywac metod obiektu b2world do tworzenia tych rzeczy.
	* czolg: dl. ~7m, wys ~3m
	* plansza w metrach: ~200m, do ustawienia w Configu
	* 
	*/