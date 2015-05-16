#pragma once
#include "Renderable.h"

class Shell : public Renderable
{
public:
	Shell();
	~Shell();

	void render();
	void renderAtBodyPosition();
};

