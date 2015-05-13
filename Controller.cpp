#include "Controller.h"
#include <GL\freeglut.h>
#include <Box2D\Box2D.h>

Controller::Controller(Config* config)
{
	view = new View(config);
}


Controller::~Controller()
{
}

void Controller::play(Game* game) {
	sf::Window *window;
	sf::Event event;
	window = view->getWindow();

	b2Vec2 gravity = b2Vec2(0.0f, -0.1f);

	b2World* world = new b2World(gravity);

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(0.0f, 4.0f);
	b2Body* body = world->CreateBody(&bodyDef);

	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;

	body->CreateFixture(&fixtureDef);
	int32 velocityIterations = 6;
	int32 positionIterations = 2;
	float32 timeStep = 1.0f / 30.0f;

	Tank* tank = new Tank(world, 1);

	bool running = true;
	while (running)
	{
		//window->clear(sf::Color::White);
		
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glMatrixMode(GL_PROJECTION);
		//gluOrtho2D(0.0, 200.0, 0.0, 150.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		world->Step(timeStep, velocityIterations, positionIterations);
		b2Vec2 position = tank->m_body->GetPosition();
		float32 angle = tank->m_body->GetAngle();
		tank->renderAtBodyPosition();
		printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
		//printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
		
		glBegin(GL_LINES);
		glColor3f(1.0f,0.0f,0.f);
		glLineWidth(3);
		glVertex2f(0,0);
		glVertex2f(0.9f, 0.9f);
		glEnd();

		// manage window events
		while (window->pollEvent(event))
		{
			switch (event.type) {
			case sf::Event::Closed:

				// ending the game
				/*
				if (game->getWinner() == NONE) {
					game->saveGamestate();
				}
				*/
				running = false;
				break;
			case sf::Event::KeyPressed:

				// key was pressed
				manageKeyEvent(event, game);

			default:
				break;
			}
		}

		window->display();
	}
}

void Controller::manageKeyEvent(sf::Event &e, Game *game) {
	/*short actionCode = KEY_OTHER;
	short player = 8;
	switch (e.key.code) {
	case sf::Keyboard::W:
		actionCode = game->getSnake(PLAYER1)->getKeyAction(KEY_UP);
		player = PLAYER1;
		break;
	case sf::Keyboard::D:
		actionCode = game->getSnake(PLAYER1)->getKeyAction(KEY_RIGHT);
		player = PLAYER1;
		break;
	case sf::Keyboard::S:
		actionCode = game->getSnake(PLAYER1)->getKeyAction(KEY_DOWN);
		player = PLAYER1;
		break;
	case sf::Keyboard::A:
		actionCode = game->getSnake(PLAYER1)->getKeyAction(KEY_LEFT);
		player = PLAYER1;
		break;
	case sf::Keyboard::Up:
		actionCode = game->getSnake(PLAYER2)->getKeyAction(KEY_UP);
		player = PLAYER2;
		break;
	case sf::Keyboard::Right:
		actionCode = game->getSnake(PLAYER2)->getKeyAction(KEY_RIGHT);
		player = PLAYER2;
		break;
	case sf::Keyboard::Down:
		actionCode = game->getSnake(PLAYER2)->getKeyAction(KEY_DOWN);
		player = PLAYER2;
		break;
	case sf::Keyboard::Left:
		actionCode = game->getSnake(PLAYER2)->getKeyAction(KEY_LEFT);
		player = PLAYER2;
		break;
	}

	if (player == PLAYER1) {
		newDirection1 = actionCode == KEY_UP ? DN : newDirection1;
		newDirection1 = actionCode == KEY_RIGHT ? DE : newDirection1;
		newDirection1 = actionCode == KEY_DOWN ? DS : newDirection1;
		newDirection1 = actionCode == KEY_LEFT ? DW : newDirection1;
	}
	else if (player == PLAYER2) {
		newDirection2 = actionCode == KEY_UP ? DN : newDirection2;
		newDirection2 = actionCode == KEY_RIGHT ? DE : newDirection2;
		newDirection2 = actionCode == KEY_DOWN ? DS : newDirection2;
		newDirection2 = actionCode == KEY_LEFT ? DW : newDirection2;
	}*/
}
