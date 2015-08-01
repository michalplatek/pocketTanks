#ifndef _WORLD_H_
#define _WORLD_H_

#include <Box2D/Box2D.h>
#include "Config.h"
#include "Renderable.h"
#include "ObjectData.h"
#include "Shell.h"

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/geometries.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/register/ring.hpp>
#include <boost/geometry/geometries/register/point.hpp>
#include <unordered_set>

BOOST_GEOMETRY_REGISTER_POINT_2D(b2Vec2, float, boost::geometry::cs::cartesian, x, y)
typedef boost::geometry::model::ring<b2Vec2, false, true> ring_t;
typedef std::pair<b2Body*, ring_t> match_t;

class World : public Renderable
{
	std::unordered_set<b2Body*> bodies;
public:
	World(Config* config);
	~World();

	std::unique_ptr<b2ChainShape> makeChain(b2Vec2* points, int count, bool closed);

	void processExplosion(Shell* shell);
	b2Vec2 getBodyPosition();
	float getBodyAngle();
	void render();

};

#endif
