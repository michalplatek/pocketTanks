#ifndef _BARREL_H_
#define _BARREL_H_

#include<Box2D\Box2D.h>
#include<GL\freeglut.h>
#include<cmath>
#include<vector>
#include "World.h"

#include "ObjectData.h"
#include <cstdlib>

/**
	Klasa: Lufa

*/
class Barrel : public Renderable
{
	/**
		k¹t obrotu czo³gu
	*/
	float TankRotate;
	/**
		k¹t obrotu lufy
	*/
	float BarrelAngle;
	/**	
		zwrot lufy
	*/
	Config::Direction HorizontalDirection;
	/**
		color lufy
	*/
	b2Vec3 color;
	

public:

	/**
		Konstruktor klasy Barrel
		@param  world obiekt œwiata
		@param	config konfiguracja œwiata
		@param  player gracz
		@param  direction zwrot lufy
	*/
	Barrel(b2World* world, Config* config, Config::Players player, Config::Direction direction);

	/**
		Funkcja obracajaca lufê
		@param float angle
		@param float tankAngle
	*/
	void rotate(float angle, float tankAngle);

	/**
		Bezargumentowy konstruktor klasy Barrel
	*/
	Barrel();

	/**
		Destruktor klasy
	*/
	~Barrel();


	/**
		Funkcja rysuj¹ca lufê
	*/
	void render();

	/**
		Funkcja zwracaj¹ca pozycjê koñca lufy
		@return po³o¿enie koñca lufy
	*/
	b2Vec2 getBarrelEndPosition();

	/**
		Funkcja zwracaj¹ca k¹t obrotu lufy
		@return k¹t obrotu lufy
	*/
	float getBarrelAngle();

	/**

		@param angle k¹t ob
	*/
	void setTankRotate(float angle);


};

#endif