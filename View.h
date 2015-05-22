#ifndef _VIEW_H_
#define _VIEW_H_

#include <SFML/Graphics.hpp>
#include <SFML/Window/Context.hpp>
#include <GL/freeglut.h>
#include "Config.h"
#include "Game.h"

class View
{
	Config* config;
public:
	View(Config* config);
	~View();
	
	sf::RenderWindow* window;
	sf::RenderWindow* getWindow();
	void viewportSetup();
	void viewportReset();
	void prepare();
	
	void renderTest();
	void render(Game* game);
	void render(Tank* tank);
	void render(World* world);

	void renderAtBodyPosition(Renderable* renderable);

};

#endif