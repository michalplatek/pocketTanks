#ifndef _TANK_H_
#define _TANK_H_

#include<Box2D\Box2D.h>
#include<GL\freeglut.h>
#include<cmath>
#include<vector>
#include "World.h"
#include "ObjectData.h"
#include <cstdlib>
#include "Barrel.h"
#include "Wheel.h"

/**
	Klasa: Czo³g.

*/
class Tank : public Renderable
{
	/**
		aktualny gracz
	*/
	Config::Players player;
	/**
		aktualny typ pocisku
	*/
	Config::ShellType loadedShellType;
	/**
		kierunek w poziomie
	*/
	Config::Direction movementHorizontal;
	/**
		kierunek w pionie
	*/
	Config::Direction movementVertical;
	/**
		wektor po³¹czeñ miêdzy obiektami
	*/
	std::vector<b2Joint*> joints;



	/**
		Funkcja tworz¹ca ko³a czo³gu. Wygenerowanie kó³ i po³¹czenie ich w odpowiednim miejscu z kad³ubem.
		@param radius promieñ ko³a
		@param position pozycja ko³a
		@param anchor obiekt do zaczepienia
	*/
	void GenerateWheel(float radius, b2Vec2 position, b2Vec2 anchor);

	/**
		Funkcja tworz¹ca lufê czo³gu. Wygenerowanie kszta³tu i po³¹czenie go z cia³em czo³gu.
		@param float radius
		@param b2Vec2 pos
		@param int direction
	*/
	void GenerateBarrel(float radius, b2Vec2 pos, int direction);

public:
	//class member variables
	/**
		promieñ kó³
	*/
	float radius;
	/**

	*/
	Barrel* barrel;
	/**
		lufa
	*/
	std::vector<Wheel*> wheels;

	/**
		Konstruktor klasy Tank - tworzenie czo³gu - kad³uba, lufy i kó³.
		@param  world wskaŸnik na obiekt œwiata
		@param  config wskaŸnik na obiekt konfiguracji
		@param  player numer gracza
	*/
	Tank(b2World* world, Config* config, Config::Players player);

	/**
		punkty wytrzyma³oœci czo³gu
	*/
	int healthPoints;
	/**
		kolor czo³gu
	*/
	b2Vec3 color;

	/**
		Konstruktor klasy Tank 
	*/
	Tank();

	/**
		Destruktor klasy
	*/
	~Tank();

	/**
		Funkcja rysuj¹ca czo³g.
	*/
	void render();

	/**
		Funkcja zwracaj¹ca aktualny wybrany typ pocisku.
		@return rodzaj za³adowanego pocisku
	*/
	Config::ShellType getLoadedShellType();

	/**
		Funkcja ustawiaj¹ca rodzaj pocisku
		@param shellType rodzaj pocisku ktory ustawiamy
	*/
	void setLoadedShellType(Config::ShellType shellType);

	/**
		Funkcja zwracaj¹ca pozycje konca lufy - potrzebna do wyliczenia wspó³rzêdnym wystrzelenia pocisku.
		@return pozycja koñca lufy
	*/
	b2Vec2 getBarrelEndPosition();

	/**
		Funkcja zwracajaca zwrot czo³gu.
		@return
	*/
	Config::Direction getHorizontalDorection();

	/**
		Funkcja zwracaj¹ca k¹t lufy.
		@return k¹t lufy
	*/
	float getBarrelAngle();

	/**
		Funkcja zatrzymujaca czo³g.

	*/
	void stop();

	/**
		Funkcja ustawiaj¹ca zwrot czo³gu oraz nadaj¹ca prêdkoœæ.
		@param direction zwrot czo³gu w poziomie
	*/
	void setHorizontalDirection(Config::Direction direction);

	/**
		Funkcja ustawiaj¹ca zwrot czo³gu oraz obracaj¹ca czo³g.
		@param direction kierunek obrotu lufy
	*/
	void setVerticalDirection(Config::Direction direction);


};

#endif