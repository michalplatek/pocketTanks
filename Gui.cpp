#include <GL/freeglut.h>
#include "Gui.h"

Gui::Gui(Config* config) : Renderable(config)
{
}

Gui::~Gui()
{
}

void Gui::setTank(Tank* tank){
	this->tank = tank;
}
void Gui::render()
{
			glColor3f(1.0f, 1.0f, 0.5f);
			glBegin(GL_QUADS);
			
			float points[8] = { -500.0, 0.0, 500.0, 0.0, 500.0, 20.0, -500.0, 20.0 };

			for (int i = 0.0; i < 4.0; i++){
				float posx = getConfig()->positionToPixel(points[i*2]);
				float posy = getConfig()->positionToPixel(points[(i*2)+1]);

				glVertex2f(posx, posy);
			}

			glEnd();

			glColor3f(0.0f, 0.0f, 0.4f);
			glBegin(GL_QUADS);

			float points2[8] = { -500.0, 19.0, 500.0, 19.0, 500.0, 20.0, -500.0, 20.0 };

			for (int i = 0.0; i < 4.0; i++){
				float posx = getConfig()->positionToPixel(points2[i * 2]);
				float posy = getConfig()->positionToPixel(points2[(i * 2) + 1]);

				glVertex2f(posx, posy);
			}

			glEnd();
}
		
	


