#include "Controller.h"
#include <GL\freeglut.h>
#include <Box2D\Box2D.h>

Controller::Controller(Config* config)
{
	view = new View(config);
	this->config = config;
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
	case sf::Event::Resized:
		// asigning new window dimensions to global configuration object
		config->WINDOW_W = e.size.width;
		config->WINDOW_H = e.size.height;
		break;
	case sf::Event::KeyPressed:
		manageKeyEvent(e, game);
	default:
		break;
	}
}

void Controller::manageKeyEvent(sf::Event &e, Game *game)
{
	if (e.key.code == config->KEY_PLAYER1_UP) {
		printf("up pressed\n");
	}
	else if (e.key.code == config->KEY_PLAYER1_DOWN) {
		printf("down pressed\n");
	}
	else if (e.key.code == config->KEY_PLAYER1_LEFT) {
		printf("left pressed\n");
	}
	else if (e.key.code == config->KEY_PLAYER1_RIGHT) {
		printf("right pressed\n");
	}
	else if (e.key.code == config->KEY_PLAYER1_FIRE) {
		printf("enter pressed\n");
	}
	else if (e.key.code == config->KEY_PLAYER2_UP) {
		printf("w pressed\n");
	}
	else if (e.key.code == config->KEY_PLAYER2_DOWN) {
		printf("s pressed\n");
	}
	else if (e.key.code == config->KEY_PLAYER2_LEFT) {
		printf("a pressed\n");
	}
	else if (e.key.code == config->KEY_PLAYER2_RIGHT) {
		printf("d pressed\n");
	}
	else if (e.key.code == config->KEY_PLAYER2_FIRE) {
		printf("space pressed\n");
	}
	else if (e.key.code == config->KEY_QUIT) {
		game->setStatus(Config::Status::FINISHED);
	}
}
