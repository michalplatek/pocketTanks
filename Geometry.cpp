#include "Geometry.h"

Geometry::Geometry() { }
Geometry::~Geometry() { }

// creates a circular ring in specified position with specified radius and number of verticies
ring_t Geometry::makeConvexRing(b2Vec2 position, float radius, int vertices) {
	ring_t convexRing;
	const float theta = boost::math::constants::two_pi<float>() / static_cast<float>(vertices);

	float cos = std::cos(theta);
	float sin = std::sin(theta);

	float t = 0.0f;
	float y = 0.0f;
	float x = radius;
	for (float i = 0; i < vertices; i++)
	{
		float v_x = x + position.x;
		float v_y = y + position.y;
		bg::append(convexRing, b2Vec2(v_x, v_y));

		t = x;
		x = cos * x - sin * y;
		y = sin * t + cos * y;
	}
	return convexRing;
}

// converts a shape to ring shape
ring_t Geometry::convertShape(b2Vec2 position, const b2ChainShape* source_shape)
{
	b2Vec2* vertices = source_shape->m_vertices;
	int vertexCount = source_shape->m_count;
	ring_t ring = { vertices, vertices + vertexCount };
	transform(ring.begin(), ring.end(), ring.begin(), [=](b2Vec2 v)
	{ 
		return v + position;
	});
	bg::correct(ring);

	return ring;
}

// convert a vector of rings to a vector of chain shapes
vector<std::unique_ptr<b2ChainShape>> Geometry::convertGeometry(const ring_collection_t& rings)
{
	std::vector<std::unique_ptr<b2ChainShape>> shapes;
	for (const ring_t& ring : rings)
	{
		std::unique_ptr<b2ChainShape> shape{ new b2ChainShape() };
		shape->CreateChain(ring.data(), ring.size());
		shapes.push_back(std::move(shape));
	}
	return shapes;
}

// subtract a ring from a shape
ring_collection_t Geometry::subtract(const ring_t& source, const ring_t& shapeToSubtract)
{
	ring_collection_t out;
	bg::difference(source, shapeToSubtract, out);
	return out;
}

// simplifies a ring
void Geometry::simplify(ring_collection_t& rings)
{
	std::transform(rings.begin(), rings.end(), rings.begin(), [](const ring_t& ring)
	{
		ring_t simplified;
		bg::simplify(ring, simplified, 0.05);
		// Discard self intersecting rings
		return bg::intersects(simplified) ? ring : simplified;
	});
}

// a world query method used for determining membersip of the fixture in the set of destructible bodies
bool WorldQueryCallback::ReportFixture(b2Fixture* fixture) {
	b2Shape::Type type = fixture->GetShape()->GetType();
	if (type == shapeFilter)
	{
		foundBodies.insert(fixture->GetBody());
	}
	return true;
}
