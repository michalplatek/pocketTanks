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

void Controller::play(Game* game)
{
	sf::Window *window;
	sf::Event event;
	window = view->getWindow();

	while (game->getStatus() == Config::Status::RUNNING)
	{
		view->prepare();
		game->step();		

		view->render(game);

		/* render test lines */
		view->renderTest();


		// manage window events
		while (window->pollEvent(event))
		{
			manageEvent(event, game);
		}
		window->display();
	}
}

void Controller::manageEvent(sf::Event &e, Game* game)
{
	switch (e.type) {
	case sf::Event::Closed:
		game->setStatus(Config::Status::FINISHED);
		break;
	case sf::Event::KeyPressed:
		manageKeyEvent(e, game);
	default:
		break;
	}
}

void Controller::manageKeyEvent(sf::Event &e, Game *game)
{
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
