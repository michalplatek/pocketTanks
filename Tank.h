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
	Klasa: Czo�g.

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
		wektor po��cze� mi�dzy obiektami
	*/
	std::vector<b2Joint*> joints;



	/**
		Funkcja tworz�ca ko�a czo�gu. Wygenerowanie k� i po��czenie ich w odpowiednim miejscu z kad�ubem.
		@param radius promie� ko�a
		@param position pozycja ko�a
		@param anchor obiekt do zaczepienia
	*/
	void GenerateWheel(float radius, b2Vec2 position, b2Vec2 anchor);

	/**
		Funkcja tworz�ca luf� czo�gu. Wygenerowanie kszta�tu i po��czenie go z cia�em czo�gu.
		@param float radius
		@param b2Vec2 pos
		@param int direction
	*/
	void GenerateBarrel(float radius, b2Vec2 pos, int direction);

public:
	//class member variables
	/**
		promie� k�
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
		Konstruktor klasy Tank - tworzenie czo�gu - kad�uba, lufy i k�.
		@param  world wska�nik na obiekt �wiata
		@param  config wska�nik na obiekt konfiguracji
		@param  player numer gracza
	*/
	Tank(b2World* world, Config* config, Config::Players player);

	/**
		punkty wytrzyma�o�ci czo�gu
	*/
	int healthPoints;
	/**
		kolor czo�gu
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
		Funkcja rysuj�ca czo�g.
	*/
	void render();

	/**
		Funkcja zwracaj�ca aktualny wybrany typ pocisku.
		@return rodzaj za�adowanego pocisku
	*/
	Config::ShellType getLoadedShellType();

	/**
		Funkcja ustawiaj�ca rodzaj pocisku
		@param shellType rodzaj pocisku ktory ustawiamy
	*/
	void setLoadedShellType(Config::ShellType shellType);

	/**
		Funkcja zwracaj�ca pozycje konca lufy - potrzebna do wyliczenia wsp�rz�dnym wystrzelenia pocisku.
		@return pozycja ko�ca lufy
	*/
	b2Vec2 getBarrelEndPosition();

	/**
		Funkcja zwracajaca zwrot czo�gu.
		@return
	*/
	Config::Direction getHorizontalDorection();

	/**
		Funkcja zwracaj�ca k�t lufy.
		@return k�t lufy
	*/
	float getBarrelAngle();

	/**
		Funkcja zatrzymujaca czo�g.

	*/
	void stop();

	/**
		Funkcja ustawiaj�ca zwrot czo�gu oraz nadaj�ca pr�dko��.
		@param direction zwrot czo�gu w poziomie
	*/
	void setHorizontalDirection(Config::Direction direction);

	/**
		Funkcja ustawiaj�ca zwrot czo�gu oraz obracaj�ca czo�g.
		@param direction kierunek obrotu lufy
	*/
	void setVerticalDirection(Config::Direction direction);


};

#endif