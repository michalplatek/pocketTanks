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
		k�t obrotu czo�gu
	*/
	float TankRotate;
	/**
		k�t obrotu lufy
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
		@param  world obiekt �wiata
		@param	config konfiguracja �wiata
		@param  player gracz
		@param  direction zwrot lufy
	*/
	Barrel(b2World* world, Config* config, Config::Players player, Config::Direction direction);

	/**
		Funkcja obracajaca luf�
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
		Funkcja rysuj�ca luf�
	*/
	void render();

	/**
		Funkcja zwracaj�ca pozycj� ko�ca lufy
		@return po�o�enie ko�ca lufy
	*/
	b2Vec2 getBarrelEndPosition();

	/**
		Funkcja zwracaj�ca k�t obrotu lufy
		@return k�t obrotu lufy
	*/
	float getBarrelAngle();

	/**

		@param angle k�t ob
	*/
	void setTankRotate(float angle);


};

#endif