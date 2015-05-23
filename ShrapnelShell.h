#ifndef _SHRAPNELSHELL_H_
#define _SHRAPNELSHELL_H_

#include "Shell.h"

	// Shrapnel Shell

class ShrapnelShell : public Shell
{
public:
	ShrapnelShell(b2World* world, Config* config, Config::Players player, b2Vec2 position, float angle);
	~ShrapnelShell();

	virtual void render();
};

#endif
