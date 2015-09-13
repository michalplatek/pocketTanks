#ifndef _WORLD_H_
#define _WORLD_H_

#include <Box2D/Box2D.h>
#include "Config.h"
#include "Renderable.h"
#include "ObjectData.h"
#include "Geometry.h"

/**
Klasa: Œwiat gry
Przechowuje obiekt œwiata i wspiera zarz¹dzanie elementami œwiata.
*/
class World : public Renderable
{
public:
	/**
	Konstruktor klasy œwiata. 
	@param config Obiekt przechowuj¹cy konfiguracjê rozgrywki.
	*/
	World(Config* config);
	/**
	Konstruktor bezparametrowy klasy œwiata
	*/
	~World();

	/**
	Konwertuje tablicê punktów na ci¹g punktów kompatybilny z bibliotek¹ Box2D
	@param points tablica punktów
	@param count iloœæ punktów w tablicy
	@param closed wskazuje, czy wynikowa pêtla ma byæ zamkniêta
	@return pêtla punktów kompatybilna z bibliotek¹ Box2D
	*/
	std::unique_ptr<b2ChainShape> makeChain(b2Vec2* points, int count, bool closed);
	/**
	Renderuje kszta³t przypisany do obiektu œwiata.
	*/
	void render();
	/**
	Zwraca zniszczalne cia³a istniej¹ce w œwiecie gry.
	@param position po³o¿enie punktu, wokó³ którego wyszukiwane s¹ zniszczalne cia³a
	@param radius promieñ wyszukiwania zniszczalnych cia³ wokó³ punktu position
	@return zestaw zniszczalnych cia³
	*/
	unordered_set<b2Body*> getDestructibleBodies(b2Vec2 position, float radius);
};

#endif
