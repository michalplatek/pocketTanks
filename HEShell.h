#ifndef _HESHELL_H_
#define _HESHELL_H_

#include "Shell.h"

	// High Explosive Shell

class HEShell : public Shell
{
public:
	HEShell(b2World* world, Config* config);
	virtual ~HEShell();
};

#endif
