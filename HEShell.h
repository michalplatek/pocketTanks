#ifndef _HESHELL_H_
#define _HESHELL_H_

#include "Shell.h"

	// High Explosive Shell

class HEShell : public Shell
{
public:
	float radius;

	HEShell(b2World* world, Config* config, b2Vec2 position, float angle);
	~HEShell();
};

#endif
