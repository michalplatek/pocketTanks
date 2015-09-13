#ifndef _GAME_H_
#define _GAME_H_

#include "World.h"
#include "Tank.h"
#include "Shell.h"
#include "Config.h"
#include "Shell.h"
#include "APShell.h"
#include "HEShell.h"
#include "ShrapnelShell.h"
#include "Particle.h"
#include <vector>
#include "Geometry.h"

/**
Klasa: Gra
Przechowuje wszystkie elementy œwiata gry, wliczaj¹c obiekt œwiata.
*/
class Game
{
	Config* config;
	World* world;
	b2ContactListener* contactListener;
	std::vector<Tank*> tanks;
	std::vector<Shell*> shells;
	std::vector<Particle*> particles;
	int turnCounter;
	
	
	Config::Status status;

public:
	/**
	Konstruktor klasy gry.
	@param config obiekt klasy Config
	*/
	Game(Config* config);
	/**
	Bezparametrowy konstruktor klasy Game
	*/
	~Game();
	int shellVelocity;

	/**
	Wykonuje jeden krok symulacji œwiata gry.
	*/
	void step();

	/**
	Zwraca obiekt œwiata gry.
	@return obiekt œwiata gry
	*/
	World* getWorld();

	/* status and turn */
	/**
	Zwraca status rozgrywki.
	@return status rozgrywki
	*/
	Config::Status getStatus();
	/**
	Ustawia status rozgrywki.
	@param status status rozgrywki
	*/
	void setStatus(Config::Status status);
	/**
	Zwraca numer tury ozgrywki
	@return numer tury rozgrywki
	*/
	int getTurn();
	/**
	Inkrementuje licznik tur rozgrywki.
	*/
	void nextTurn();
	/**
	Sprawdza, czy jest tura danego gracza.
	@param player WskaŸnik na obiekt gracza
	*/
	bool isTurnOf(Config::Players player);
	/**
	Zwraca numer gracza, którego tura jest w danej chwili.
	@return numer gracza, którego tura jest obecnie
	*/
	Config::Players currentPlayer();
	
	/* tanks */
	/**
	Zwraca czo³g z tablicy czo³gów.
	@param i indeks czo³gu w tablicy czo³gów
	@return WskaŸnik na obiekt czo³gu
	*/
	Tank* getTank(int i);
	/**
	Zwraca czo³g nale¿¹cy do danego gracza.
	@param player numer gracza
	@return obiekt czo³gu nale¿¹cy do danego gracza
	*/
	Tank* getTank(Config::Players player);
	
	/* shells and shots */
	/**
	Zwraca pocisk z tablicy pocisków.
	@param i indeks pocisku w tablicy pocisków
	@return wskaŸnik na obiekt pocisku
	*/
	Shell* getShell(int i);
	/**
	Zwraca iloœæ pocisków istniej¹cych w grze.
	@return iloœæ pocisków istniej¹cych w grze.
	*/
	int numberOfShells();
	/**
	Niszczy pociski istniej¹ce w grze.
	*/
	void removeShells();
	/**
	Niszczy obiekt pocisku w tablicy pocisków.
	@param i indeks pocisku w tablicy pocisków
	*/
	void removeShell(int i);
	/**
	Wywpo³uje akcjê strza³u skutkuj¹c¹ utworzeniem obiektu pocisku.
	@param player numer gracza wykonuj¹cego strza³
	*/
	void shoot(Config::Players player);
	/**
	Wykonuje analizê obiektów œwiata gry pod k¹tem zaistnienia kolizji pocisków z innymi obiektami.
	*/
	void resolveCollisions();
	/**
	Wykonuje operacje na obiekcie œwiata gry zwi¹zane z kolizj¹ pocisku z elementem planszy.
	@param shell obiekt pocisku wchodz¹cego w kolizjê z elementem planszy
	*/
	void damageWorld(Shell* shell);
	/**
	Wykonuje operacje zwi¹zane z wybuchem pocisku w efekcie kolizji
	@param shellIndex index pocisku w tablicy pocisków
	*/
	void boom(int shellIndex);
	/**
	Zwraca zniszczalne cia³a istniej¹ce w œwiecie gry.
	@param position po³o¿enie punktu, wokó³ którego wyszukiwane s¹ zniszczalne cia³a
	@param radius promieñ wyszukiwania zniszczalnych cia³ wokó³ punktu position
	@return zestaw zniszczalnych cia³
	*/
	unordered_set<b2Body*> destructibleBodies(b2Vec2 position, float radius);
};

#endif
