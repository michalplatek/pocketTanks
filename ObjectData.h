#ifndef _OBJECTDATA_H_
#define _OBJECTDATA_H_
#include "Config.h"

typedef struct _BodyData
{
	Config::BodyType bodyType;
	Config::Players owner;

} BodyData;

typedef struct _FixtureData
{
	Config::FixtureType fixtureType;
	Config::Players owner;

} FixtureData;

#endif
