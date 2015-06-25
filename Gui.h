#ifndef _GUI_H_
#define _GUI_H_

#include "Config.h"
#include "Renderable.h"
#include "Tank.h"


class Gui : public Renderable
{
private:
	Config* config;
	Tank* tank;
public:
	Gui(Config* config);
	~Gui();

	void setTank(Tank* tank);
	void render();
};

#endif