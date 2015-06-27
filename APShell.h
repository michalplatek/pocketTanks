#ifndef _APSHELL_H_
#define _APSHELL_H_

#include "Shell.h"
#include "FreeGlutHelper.h"

	// Armour Piercing Shell

class APShell : public Shell
{
public:
	APShell(b2World* world, Config* config, Config::Players player, b2Vec2 position, float angle);
	~APShell();

	void render();
};

#endif
