#ifndef _SHRAPNELSHELL_H_
#define _SHRAPNELSHELL_H_

#include "Shell.h"

	// Shrapnel Shell

class ShrapnelShell : public Shell
{
public:
	ShrapnelShell(b2World* world, Config* config);
	virtual ~ShrapnelShell();
};

#endif
