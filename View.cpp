#include "View.h"
//#include <ft2build.h>
//#include FT_FREETYPE_H

View::View(Config* config) : config(config)
{
	sf::ContextSettings Settings;
	Settings.depthBits = config->WINDOW_DEPTH_BITS;
	Settings.stencilBits = config->WINDOW_STENCIL_BITS;
	Settings.antialiasingLevel = config->WINDOW_ANTIALIASING_LEVEL;
	Settings.majorVersion = config->WINDOW_MAJOR_VERSION;
	Settings.minorVersion = config->WINDOW_MINOR_VERSION;

	window = new sf::Window(sf::VideoMode(config->WINDOW_W, config->WINDOW_H), config->WINDOW_TITLE, sf::Style::Default, Settings);
	window->setVerticalSyncEnabled(true);
	window->setKeyRepeatEnabled(true);

	

	viewportSetup();
}

View::~View()
{

}

sf::Window* View::getWindow() 
{
	return window;
}

void View::viewportSetup()
{
	glViewport(0, 0, config->WINDOW_W, config->WINDOW_H);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	viewportReset();
}

void View::viewportReset()
{
	float ratio = (float)config->WINDOW_H / (float)config->WINDOW_W;
	gluOrtho2D(0.0f, config->positionToPixel(config->LEVEL_SIZE_IN_METRES), 0.0f, config->positionToPixel(ratio * config->LEVEL_SIZE_IN_METRES));
}

void View::prepare() 
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void View::renderTest() 
{
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.f);
	glLineWidth(3);
	glVertex2f(0, 0);
	glVertex2f(500.0f, 500.0f);
	glEnd();
}

void View::render(Game* game) 
{
	render(game->getWorld());
	for (int i = 0; i < config->NUM_TANKS; i++) {
		render(game->getTank(i));
	}
	int shells = game->numberOfShells();
	if (shells > 0)
	{
		for (int i = 0; i < shells; i++)
		{
			render(game->getShell(i));
		}
	}
}

void View::render(World* world) 
{
	renderAtBodyPosition(world);
}

void View::render(Gui* gui){
	gui->render();
}

void View::renderAtBodyPosition(Renderable* renderable) {
	//get current position from Box2D
	b2Vec2 position = renderable->getBodyPosition();
	float angle = renderable->getBodyAngle();

	position.x = config->positionToPixel(position.x);
	position.y = config->positionToPixel(position.y);

	//call normal render at different position/rotation
	glPushMatrix();
	glTranslatef(position.x, position.y, 0);
	glRotatef(angle * 180 / 3.1415f, 0, 0, 1);//OpenGL uses degrees here
	renderable->render();//normal render at (0,0)
	glPopMatrix();
	
}

void View::render(Tank* tank)
{
	renderAtBodyPosition(tank);
}

void View::render(Shell* shell)
{
	renderAtBodyPosition(shell);
}