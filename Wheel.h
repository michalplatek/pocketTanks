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
	Klasa: Ko³o.

*/
class Wheel : public Renderable
{

	/**
		promieñ ko³a
	*/
	float radius;


public:
	//class member variables

	/**
		Konstruktor ko³a - tworzenie kszta³tu i dodawanie go do œwiata.
		@param  world obiekt œwiata
		@param  config konfiguracja œwiata
		@param  player numer gracza
		@param  radius promieñ ko³a
	*/
	Wheel(b2World* world, Config* config, Config::Players player, float radius);

	/**
		Funkcja obracaj¹ca ko³o
	*/
	void rotate(float angle);

	/**
		Bezargumentowy konstruktor
		@param angle k¹t obrotu
	*/
	Wheel();

	/**
		Destruktor klasy
	*/
	~Wheel();

	/**
		Funkcja rysuj¹ca ko³o.
	*/
	void render();



};

#endif 