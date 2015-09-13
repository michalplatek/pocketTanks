#ifndef _RENDERABLE_H_
#define _RENDERABLE_H_
#include <Box2D/Box2D.h>
#include "Config.h"


/**
Klasa: Obiekt renderowalny
Obiekt, kt�ry mo�na wyrenderowa� w oknie aplikacji
*/
class Renderable
{
protected:

	b2Body* body;
	b2World* world;
	Config* config;

public:
	/**
	Konstruktor klasy Renderable
	@param config Obiekt przechowuj�cy konfiguracj� rozgrywki
	*/
	Renderable(Config* config);
	/**
	Destruktor klasy Renderable
	*/
	virtual ~Renderable();
	/**
	Renderuje obiekt.
	*/
	virtual void render() = 0;

	/**
	Zwraca cia�o obiektu w �wiecie gry.
	@return cia�o obiektu w �wiecie gry
	*/
	b2Body* getBody();
	/**
	Ustawia cia�o obiektu renderowalnego w �wiecie gry.
	@param body cia�o obiektu renderowalnego
	*/
	void setBody(b2Body* body);

	/**
	Zwraca obiekt �wiata gry
	@return obiekt �wiata gry
	*/
	b2World* getWorld();
	/**
	Ustawia obiekt �wiata gry
	@param world obiekt �wiata gry
	@return
	*/
	void setWorld(b2World* world);

	/**
	Zwraca po�o�enie cia�a obiektu renderowalnego w �wiecie gry.
	@return wektor po�o�enia obiektu renderowalnego w �wiecie gry
	*/
	b2Vec2 getBodyPosition();
	/**
	Zwraca k�t obrotu cia�a obiektu renderowalnego
	@return k�t obrotu cia�a obiektu renderowalnego
	*/
	float getBodyAngle();

	/**
	Zwraca obiekt konfiguracji rozgrywki
	@return obiekt konfiguracji rozgrywki
	*/
	Config* getConfig();
};

#endif
