#ifndef _RENDERABLE_H_
#define _RENDERABLE_H_
#include <Box2D/Box2D.h>
#include "Config.h"


/**
Klasa: Obiekt renderowalny
Obiekt, który mo¿na wyrenderowaæ w oknie aplikacji
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
	@param config Obiekt przechowuj¹cy konfiguracjê rozgrywki
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
	Zwraca cia³o obiektu w œwiecie gry.
	@return cia³o obiektu w œwiecie gry
	*/
	b2Body* getBody();
	/**
	Ustawia cia³o obiektu renderowalnego w œwiecie gry.
	@param body cia³o obiektu renderowalnego
	*/
	void setBody(b2Body* body);

	/**
	Zwraca obiekt œwiata gry
	@return obiekt œwiata gry
	*/
	b2World* getWorld();
	/**
	Ustawia obiekt œwiata gry
	@param world obiekt œwiata gry
	@return
	*/
	void setWorld(b2World* world);

	/**
	Zwraca po³o¿enie cia³a obiektu renderowalnego w œwiecie gry.
	@return wektor po³o¿enia obiektu renderowalnego w œwiecie gry
	*/
	b2Vec2 getBodyPosition();
	/**
	Zwraca k¹t obrotu cia³a obiektu renderowalnego
	@return k¹t obrotu cia³a obiektu renderowalnego
	*/
	float getBodyAngle();

	/**
	Zwraca obiekt konfiguracji rozgrywki
	@return obiekt konfiguracji rozgrywki
	*/
	Config* getConfig();
};

#endif
