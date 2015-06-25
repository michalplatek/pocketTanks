#ifndef _GUI_H_
#define _GUI_H_

#include "Config.h"
#include "Renderable.h"
#include "Tank.h"
//#include <SFML\Window.hpp>
#include<SFML/Graphics/RenderWindow.hpp>

class Gui : public Renderable
{
private:
	Config* config;
	Tank* tank;
	sf::Window* window;
public:
	Gui(Config* config, sf::Window *window);
	~Gui();

	void setTank(Tank* tank);
	void render();
};

#endif