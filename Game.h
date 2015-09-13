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
Przechowuje wszystkie elementy �wiata gry, wliczaj�c obiekt �wiata.
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
	Wykonuje jeden krok symulacji �wiata gry.
	*/
	void step();

	/**
	Zwraca obiekt �wiata gry.
	@return obiekt �wiata gry
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
	@param player Wska�nik na obiekt gracza
	*/
	bool isTurnOf(Config::Players player);
	/**
	Zwraca numer gracza, kt�rego tura jest w danej chwili.
	@return numer gracza, kt�rego tura jest obecnie
	*/
	Config::Players currentPlayer();
	
	/* tanks */
	/**
	Zwraca czo�g z tablicy czo�g�w.
	@param i indeks czo�gu w tablicy czo�g�w
	@return Wska�nik na obiekt czo�gu
	*/
	Tank* getTank(int i);
	/**
	Zwraca czo�g nale��cy do danego gracza.
	@param player numer gracza
	@return obiekt czo�gu nale��cy do danego gracza
	*/
	Tank* getTank(Config::Players player);
	
	/* shells and shots */
	/**
	Zwraca pocisk z tablicy pocisk�w.
	@param i indeks pocisku w tablicy pocisk�w
	@return wska�nik na obiekt pocisku
	*/
	Shell* getShell(int i);
	/**
	Zwraca ilo�� pocisk�w istniej�cych w grze.
	@return ilo�� pocisk�w istniej�cych w grze.
	*/
	int numberOfShells();
	/**
	Niszczy pociski istniej�ce w grze.
	*/
	void removeShells();
	/**
	Niszczy obiekt pocisku w tablicy pocisk�w.
	@param i indeks pocisku w tablicy pocisk�w
	*/
	void removeShell(int i);
	/**
	Wywpo�uje akcj� strza�u skutkuj�c� utworzeniem obiektu pocisku.
	@param player numer gracza wykonuj�cego strza�
	*/
	void shoot(Config::Players player);
	/**
	Wykonuje analiz� obiekt�w �wiata gry pod k�tem zaistnienia kolizji pocisk�w z innymi obiektami.
	*/
	void resolveCollisions();
	/**
	Wykonuje operacje na obiekcie �wiata gry zwi�zane z kolizj� pocisku z elementem planszy.
	@param shell obiekt pocisku wchodz�cego w kolizj� z elementem planszy
	*/
	void damageWorld(Shell* shell);
	/**
	Wykonuje operacje zwi�zane z wybuchem pocisku w efekcie kolizji
	@param shellIndex index pocisku w tablicy pocisk�w
	*/
	void boom(int shellIndex);
	/**
	Zwraca zniszczalne cia�a istniej�ce w �wiecie gry.
	@param position po�o�enie punktu, wok� kt�rego wyszukiwane s� zniszczalne cia�a
	@param radius promie� wyszukiwania zniszczalnych cia� wok� punktu position
	@return zestaw zniszczalnych cia�
	*/
	unordered_set<b2Body*> destructibleBodies(b2Vec2 position, float radius);
};

#endif
