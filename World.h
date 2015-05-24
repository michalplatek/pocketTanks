#ifndef _WORLD_H_
#define _WORLD_H_

#include <Box2D/Box2D.h>
#include "Config.h"
#include "Renderable.h"
#include "ObjectData.h"

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/geometries.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/register/ring.hpp>
#include <boost/geometry/geometries/register/point.hpp> 

namespace bg = boost::geometry;

BOOST_GEOMETRY_REGISTER_POINT_2D(b2Vec2, float, bg::cs::cartesian, x, y)
typedef model::ring<b2Vec2, false, true> ring_t;

class World : public Renderable
{
public:
	World(Config* config);
	~World();

	void render();
};

#endif
