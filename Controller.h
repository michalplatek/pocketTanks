#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <SFML\Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "View.h"
#include "Game.h"
#include "Config.h"

/**
Klasa: Kontroler
Steruje przebiegiem rozgrywki. Obs³uguje interakcjê z u¿ytkownikiem. Zarz¹dza wyœwietlaniem.
*/
class Controller
{
public:
	View view;
	Config* config;
	bool isShooting;

	/**
	Przeprowadza analizê zdarzenia pochodz¹cego od u¿ytkownikiem.
	@param e referencja do obiektu zdarzenia
	@param game wskaŸnik na obiekt gry
	*/
	void manageEvent(sf::Event &e, Game* game);
	/**
	Przeprowadza anlizê zdarzenia pochodz¹cego z klawiatury.
	@param e referencja do obiektu zdarzenia
	@param game wskaŸnik na obiekt gry
	*/
	void manageKeyEvent(sf::Event &e, Game *game);
	/**
	Rozpoczyna rozgrywkê.
	@param game obiekt gry, na którym ma byæ prowadzona rozgrywka.
	*/
	void play(Game *game);

	/**
	Konstruktor klasy Kontrolera.
	@param config Obiekt przechowuj¹cy konfiguracjê rozgrywki.
	@return 
	*/
	Controller(Config* config);
	/**
	Bezparametrowy konstruktor klasy Kontrolera.
	*/
	~Controller();
};

#endif