#ifndef _SHRAPNELSHELL_H_
#define _SHRAPNELSHELL_H_

#include "Shell.h"

/**
	Klasa: Shrapnel Shell
	Dziedziczy po klasie Shell.
*/
class ShrapnelShell : public Shell
{
public:
	/**
		Konstruktor klasy ShrapnelShell.
		@param b2World* world
		@param Config* config
		@param Players player
		@param b2Vec2 position
		@param float angle
		@param int shellVelocity
	*/
	ShrapnelShell(b2World* world, Config* config, Config::Players player, b2Vec2 position, float angle, int shellVelocity);
	/**
		Destruktor klasy ShrapnelShell.
	*/
	~ShrapnelShell();
	/**
		Funkcja odpowiadaj¹ca za wyrysowanie pocisku na planszy.
	*/
	void render();
};

#endif
