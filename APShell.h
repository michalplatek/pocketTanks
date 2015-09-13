#ifndef _APSHELL_H_
#define _APSHELL_H_

#include "Shell.h"
#include <GL/freeglut.h>

/**
	Klasa: Armour Piercing Shell.
	Dziedziczy po klasie Shell.
*/
class APShell : public Shell
{
public:
	/**
		Konstruktor klasy APShell.
		@param b2World* world
		@param Config* config
		@param Players player
		@param b2Vec2 position
		@param float angle
		@param int shellVelocity
	*/
	APShell(b2World* world, Config* config, Config::Players player, b2Vec2 position, float angle, int shellVelocity);
	/**
		Destruktor klasy APShell.
	*/
	~APShell();
	/**
		Funkcja odpowiadaj¹ca za wyrysowanie pocisku na planszy.
	*/
	void render();
};

#endif
