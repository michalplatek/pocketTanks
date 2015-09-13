#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <SFML\Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "View.h"
#include "Game.h"
#include "Config.h"

/**
Klasa: Kontroler
Steruje przebiegiem rozgrywki. Obs�uguje interakcj� z u�ytkownikiem. Zarz�dza wy�wietlaniem.
*/
class Controller
{
public:
	View view;
	Config* config;
	bool isShooting;

	/**
	Przeprowadza analiz� zdarzenia pochodz�cego od u�ytkownikiem.
	@param e referencja do obiektu zdarzenia
	@param game wska�nik na obiekt gry
	*/
	void manageEvent(sf::Event &e, Game* game);
	/**
	Przeprowadza anliz� zdarzenia pochodz�cego z klawiatury.
	@param e referencja do obiektu zdarzenia
	@param game wska�nik na obiekt gry
	*/
	void manageKeyEvent(sf::Event &e, Game *game);
	/**
	Rozpoczyna rozgrywk�.
	@param game obiekt gry, na kt�rym ma by� prowadzona rozgrywka.
	*/
	void play(Game *game);

	/**
	Konstruktor klasy Kontrolera.
	@param config Obiekt przechowuj�cy konfiguracj� rozgrywki.
	@return 
	*/
	Controller(Config* config);
	/**
	Bezparametrowy konstruktor klasy Kontrolera.
	*/
	~Controller();
};

#endif