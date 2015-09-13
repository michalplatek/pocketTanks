#ifndef _WORLD_H_
#define _WORLD_H_

#include <Box2D/Box2D.h>
#include "Config.h"
#include "Renderable.h"
#include "ObjectData.h"
#include "Geometry.h"

/**
Klasa: �wiat gry
Przechowuje obiekt �wiata i wspiera zarz�dzanie elementami �wiata.
*/
class World : public Renderable
{
public:
	/**
	Konstruktor klasy �wiata. 
	@param config Obiekt przechowuj�cy konfiguracj� rozgrywki.
	*/
	World(Config* config);
	/**
	Konstruktor bezparametrowy klasy �wiata
	*/
	~World();

	/**
	Konwertuje tablic� punkt�w na ci�g punkt�w kompatybilny z bibliotek� Box2D
	@param points tablica punkt�w
	@param count ilo�� punkt�w w tablicy
	@param closed wskazuje, czy wynikowa p�tla ma by� zamkni�ta
	@return p�tla punkt�w kompatybilna z bibliotek� Box2D
	*/
	std::unique_ptr<b2ChainShape> makeChain(b2Vec2* points, int count, bool closed);
	/**
	Renderuje kszta�t przypisany do obiektu �wiata.
	*/
	void render();
	/**
	Zwraca zniszczalne cia�a istniej�ce w �wiecie gry.
	@param position po�o�enie punktu, wok� kt�rego wyszukiwane s� zniszczalne cia�a
	@param radius promie� wyszukiwania zniszczalnych cia� wok� punktu position
	@return zestaw zniszczalnych cia�
	*/
	unordered_set<b2Body*> getDestructibleBodies(b2Vec2 position, float radius);
};

#endif
