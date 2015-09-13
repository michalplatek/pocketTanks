#ifndef _GUI_H_
#define _GUI_H_

#include "Config.h"
#include "Renderable.h"
#include "Tank.h"
#include "Game.h"
#include<SFML/Graphics/RenderWindow.hpp>
/**
	Klasa: Gui (wyúwietla aktualne postÍpy gry).
	Dziedziczy po klasie Renderable w celu wyrysowania na planszy GUI.
*/
class Gui : public Renderable
{
private:
	/**
		Wskaünik do konfiguracji rozgrywki.
	*/
	Config* config;
	/**
		Wskaünik do obiektu gry.
	*/
	Game* game;
	/**
		Wskaünik do okna z biblioteki sfml.
	*/
	sf::RenderWindow* window;
public:
	/**
		Konstruktor klasy GUI.
		@param Config* config
		@param RenderWindow *window
	*/
	Gui(Config* config, sf::RenderWindow *window);
	/**
		Destruktor klasy GUI.
	*/
	~Gui();
	/**
		Funckja do przekazywania obiektu gry.
		@param Game
	*/
	void passGame(Game*);
	/**
		Funkcja do renderowania GUI.
	*/
	void render();
};

#endif