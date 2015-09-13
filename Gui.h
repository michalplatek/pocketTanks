#ifndef _GUI_H_
#define _GUI_H_

#include "Config.h"
#include "Renderable.h"
#include "Tank.h"
#include "Game.h"
#include<SFML/Graphics/RenderWindow.hpp>
/**
	Klasa: Gui (wy�wietla aktualne post�py gry).
	Dziedziczy po klasie Renderable w celu wyrysowania na planszy GUI.
*/
class Gui : public Renderable
{
private:
	/**
		Wska�nik do konfiguracji rozgrywki.
	*/
	Config* config;
	/**
		Wska�nik do obiektu gry.
	*/
	Game* game;
	/**
		Wska�nik do okna z biblioteki sfml.
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