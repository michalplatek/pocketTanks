#ifndef _VIEW_H_
#define _VIEW_H_

#include <SFML/Graphics.hpp>
#include <SFML/Window/Context.hpp>
#include "Config.h"

class View
{

public:
	View(Config* config);
	~View();
	
	sf::RenderWindow* window;
	sf::RenderWindow* getWindow();
};

#endif