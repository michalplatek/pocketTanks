#ifndef _HESHELL_H_
#define _HESHELL_H_

#include "Shell.h"
#include "GL\freeglut.h"

/**
	Klasa: High Explosive Shell.
	Dzieczy po klasie Shell.
*/
class HEShell : public Shell
{
public:
	/**
		Parametr okre�laj�cy d�ugo�� promienia ko�a b�d�cego pociskiem. 
	*/
	float radius;
	/**
		Konstruktor klasy HEShell.
		@param b2World* world
		@param Config* config
		@param Players player
		@param b2Vec2 position
		@param float angle
		@param int shellVelocity
	*/
	HEShell(b2World* world, Config* config, Config::Players player, b2Vec2 position, float angle, int shellVelocity);
	/**
		Destruktor klasy HEShell.
	*/
	~HEShell();
	/**
		Funkcja odpowiadaj�ca za wyrysowanie pocisku na planszy.
	*/
	void render();
};

#endif
