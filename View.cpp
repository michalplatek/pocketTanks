#include "View.h"

View::View(Config* config)
{
	this->config = config;
	sf::ContextSettings Settings;
	Settings.depthBits = config->WINDOW_DEPTH_BITS;
	Settings.stencilBits = config->WINDOW_STENCIL_BITS;
	Settings.antialiasingLevel = config->WINDOW_ANTIALIASING_LEVEL;
	Settings.majorVersion = config->WINDOW_MAJOR_VERSION;
	Settings.minorVersion = config->WINDOW_MINOR_VERSION;

	window = new sf::RenderWindow(sf::VideoMode(config->WINDOW_W, config->WINDOW_H), config->WINDOW_TITLE, sf::Style::Default, Settings);
	window->setVerticalSyncEnabled(true);
	window->setKeyRepeatEnabled(false);
}

View::~View()
{

}

sf::RenderWindow* View::getWindow() 
{
	return window;
}

void View::prepare() 
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	//gluOrtho2D(0.0, 200.0, 0.0, 150.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void View::renderTest() 
{
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.f);
	glLineWidth(3);
	glVertex2f(0, 0);
	glVertex2f(0.9f, 0.9f);
	glEnd();
}

void View::render(Game* game) 
{
	render(game->getWorld());
	for (int i = 0; i < config->NUM_TANKS; i++) {
		render(game->getTank(i));
	}
	/*b2Vec2 position = tank->m_body->GetPosition();
	float32 angle = tank->m_body->GetAngle();
	tank->renderAtBodyPosition();
	printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);*/
	//printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
}

void View::render(World* world) 
{

}

void View::renderAtBodyPosition(Tank* tank) {
	//get current position from Box2D
	b2Vec2 pos = tank->body->GetPosition();
	float angle = tank->body->GetAngle();

	//call normal render at different position/rotation
	glPushMatrix();
	glTranslatef(pos.x, pos.y, 0);
	glRotatef(angle * 180 / 3.1415, 0, 0, 1);//OpenGL uses degrees here
	render(tank);//normal render at (0,0)
	glPopMatrix();
}

void View::render(Tank* tank) {
	glColor3f(1, 1, 1);//white

	//nose and eyes
	glPointSize(4);
	glBegin(GL_POINTS);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(-0.5f, 0.5f);
	glVertex2f(0.5f, 0.5f);
	glEnd();

	//mouth
	glBegin(GL_LINES);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(-0.16f, -0.6f);
	glVertex2f(0.16f, -0.6f);
	glVertex2f(0.5f, -0.5f);
	glEnd();

	//circle outline
	glBegin(GL_LINE_LOOP);
	for (float a = 0; a < 360 * 3.1415 / 180; a += 30 * 3.1415 / 180)
		glVertex2f(sinf(a), cosf(a));
	glEnd();

	b2Vec2 vel = tank->body->GetLinearVelocity();
	float red = vel.Length() / 20.0;
	red = fmin(1, red);
	glColor3f(red, 0.5, 0.5);
}