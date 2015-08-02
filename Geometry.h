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

class Geometry
{
public:
	Geometry();
	~Geometry();

	// static members, more info in the .cpp file
	static ring_t makeConvexRing(b2Vec2 position, float radius, int vertices);
	static ring_t convertShape(b2Vec2 position, const b2ChainShape* source_shape);
	static std::vector<std::unique_ptr<b2ChainShape>> convertGeometry(const ring_collection_t& rings);
	static ring_collection_t subtract(const ring_t& source, const ring_t& subtrahend);
	static void simplify(ring_collection_t& rings);
};

// this struct allows to quickly get the destructible bodies from the world
struct WorldQueryCallback : public b2QueryCallback
{
	WorldQueryCallback(b2Shape::Type filter) : shapeFilter(filter) { }
	bool ReportFixture(b2Fixture* fixture) override;
	unordered_set<b2Body*> foundBodies;
	b2Shape::Type shapeFilter;
};

#endif
