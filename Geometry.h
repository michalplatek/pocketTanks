#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_

#include <Box2D/Box2D.h>
#include <boost/geometry.hpp>
#include <boost/geometry/geometries/geometries.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/register/ring.hpp>
#include <boost/geometry/geometries/register/point.hpp>
#include <unordered_set>
namespace bg = boost::geometry;
using namespace std;

BOOST_GEOMETRY_REGISTER_POINT_2D(b2Vec2, float, bg::cs::cartesian, x, y)

// custom types used in the world destruction process
typedef bg::model::ring<b2Vec2, false, true> ring_t;
typedef pair<b2Body*, ring_t> match_t;
typedef vector<ring_t> ring_collection_t;

/**
Klasa: Przeliczenia geometrii �wiata
S�u�y do przeliczenia geometrii �wiata, zawiera algebr� figur geometrycznych
*/
class Geometry
{
public:
	/**
	Konstruktor klasy Geometry
	@param
	@return
	*/
	Geometry();
	/**
	Destruktor klasy Geometry
	@param
	@return
	*/
	~Geometry();

	// static members, more info in the .cpp file
	/**
	Tworzy wypuk�y okr�g.
	@param position po�o�enie w �wiecie gry
	@param radius promie� okr�gu
	@param vertices ilo�� punkt�w wchodz�cych w sk�ad okr�gu
	@return wypuk�y okr�g (kszta�t)
	*/
	static ring_t makeConvexRing(b2Vec2 position, float radius, int vertices);
	/**
	Konwertuje obiekt typu b2ChainShape na typ ring_t
	@param position po�o�enie wynikowego obiektu typu ring_t
	@return obiekt typu ring_t
	*/
	static ring_t convertShape(b2Vec2 position, const b2ChainShape* source_shape);
	/**
	Konwertuje geometri� na wektor kszta�t�w typu b2ChainShape
	@param rings zestaw pier�cieni do przekonwertowania
	@return wektor kszta�t�w typu b2ChainShape
	*/
	static std::vector<std::unique_ptr<b2ChainShape>> convertGeometry(const ring_collection_t& rings);
	/**
	Wykonuje operacj� odejmowania kszta�tu od 
	@param source pierwszy kszta�t (odjemna)
	@param subtrahend odjemnik
	@return kolekcja kszta�t�w stanowi�ca wynik odejmowania
	*/
	static ring_collection_t subtract(const ring_t& source, const ring_t& subtrahend);
	/**
	Upraszcz geometri�
	@param rings kolekcja kszta�t�w typu ring_t
	*/
	static void simplify(ring_collection_t& rings);
};

// this struct allows to quickly get the destructible bodies from the world
/**
Klasa: Zapytanie do �wiata Box2D
*/
struct WorldQueryCallback : public b2QueryCallback
{
	/**
	Konstruktor klasy WorldQueryCallback.
	@param filter Filtr obiekt�w, po kt�rych iteruje zapytanie do �wiata
	*/
	WorldQueryCallback(b2Shape::Type filter) : shapeFilter(filter) { }
	/**
	Decyduje o za��czenia obiektu �wiata w kolekcji wynikowej zapytania.
	@param fixture obiekt typu fixture
	@return decyzja o w��czeniu obiektu do kolekcji wynikowej zapytania
	*/
	bool ReportFixture(b2Fixture* fixture) override;

	unordered_set<b2Body*> foundBodies;
	b2Shape::Type shapeFilter;
};

#endif
