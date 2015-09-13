#ifndef _WHEEL_H_
#define _WHEEL_H_

#include<Box2D\Box2D.h>
#include<GL\freeglut.h>
#include<cmath>
#include<vector>
#include "World.h"
#include "ObjectData.h"
#include <cstdlib>


/**
	Klasa: Ko�o.

*/
class Wheel : public Renderable
{

	/**
		promie� ko�a
	*/
	float radius;


public:
	//class member variables

	/**
		Konstruktor ko�a - tworzenie kszta�tu i dodawanie go do �wiata.
		@param  world obiekt �wiata
		@param  config konfiguracja �wiata
		@param  player numer gracza
		@param  radius promie� ko�a
	*/
	Wheel(b2World* world, Config* config, Config::Players player, float radius);

	/**
		Funkcja obracaj�ca ko�o
	*/
	void rotate(float angle);

	/**
		Bezargumentowy konstruktor
		@param angle k�t obrotu
	*/
	Wheel();

	/**
		Destruktor klasy
	*/
	~Wheel();

	/**
		Funkcja rysuj�ca ko�o.
	*/
	void render();



};

#endif 