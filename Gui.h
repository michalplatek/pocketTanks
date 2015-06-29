#ifndef _GUI_H_
#define _GUI_H_

#include "Config.h"
#include "Renderable.h"
#include "Tank.h"
#include "Game.h"
#include<SFML/Graphics/RenderWindow.hpp>

class Gui : public Renderable
{
private:
	Config* config;
	Tank* tank;
	sf::RenderWindow* window;
public:
	Gui(Config* config, sf::RenderWindow *window);
	~Gui();

	void setTank(Tank* tank);
	void render();
};

#endif