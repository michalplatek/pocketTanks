#ifndef _APSHELL_H_
#define _APSHELL_H_

#include "Shell.h"

	// Armour Piercing Shell

class APShell : public Shell
{
public:
	APShell(b2World* world, Config* config, b2Vec2 position, float angle);
	~APShell();
};

#endif