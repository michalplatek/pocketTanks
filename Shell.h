#ifndef _SHELL_H_
#define _SHELL_H_

#include "Renderable.h"
#include "World.h"
#include "Geometry.h"

/**
	Klasa: Shell.
	Dziedziczy po klasie Renderable (odpowiadaj¹cej za wyrysowanie elementów).
*/
class Shell : public Renderable
{
	/**
		Typ pocisku.
	*/
	Config::ShellType shellType;
	/**
		Eksplozja.
	*/
	ring_t explosion;

public:
	/**
		Konstruktor klasy Shell.
		@param b2World* world
		@param Config* config
		@param Players player
		@param ShellType shellType
		@param b2Vec2 position
		@param float angle
		@param int shellVelocity
	*/
	Shell(b2World* world, Config* config, Config::Players player, Config::ShellType shellType, b2Vec2 position, float angle, int shellVelocity);
	/**
		Wirtualny destruktor pocisku.
	*/
	virtual ~Shell();
	/**
		Funkcja pobieraj¹ca typ pocisku.
		@return ShellType
	*/
	Config::ShellType getShellType();
	/**
		Funkcja wykrywaj¹ca kolizje.
		@return bool
	*/
	bool collision();
	/**
		Funkcja zwracaj¹ca gracza, którego dotknê³a kolizja.
		@return Players
	*/
	Config::Players GetObjectCollision();
	/**
		Funkcja wykrywaj¹ca odbicie.
		@return bool
	*/
	bool shouldBounce();
	/**
		Funkcja odpowiadaj¹ca za odbicie.
	*/
	void bounce();
	/**
		Funkcja odpowiadaj¹ca za wybuch.
	*/
	void explode();
	/**
		Funkcja wykrywaj¹ca interakcje.
		@param unordered_set<b2Body*> destructibleBodies
	*/
	void interactWith(unordered_set<b2Body*> destructibleBodies);
	/**
		Template odpowiadaj¹cy za zwrot par (cia³o + pierœcieñ).
	*/
	template<typename It> std::vector<match_t> matchBodiesToRings(It begin, It end);
	/**
		Wirtualna funkcja odpowiadaj¹ca za wyrysowanie pocisku na planszy.
	*/
	virtual void render() = 0;
};

#endif
