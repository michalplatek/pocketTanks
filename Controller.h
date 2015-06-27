#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <SFML\Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "FreeGlutHelper.h"
#include <Box2D\Box2D.h>
#include "Gui.h"
#include "View.h"
#include "Game.h"
#include "Config.h"

class Controller
{
public:
	View view;
	Config* config;

	void manageEvent(sf::Event &e, Game* game);
	void manageKeyEvent(sf::Event &e, Game *game);
	void play(Game *game);

	Controller(Config* config);
	~Controller();
};

#endif