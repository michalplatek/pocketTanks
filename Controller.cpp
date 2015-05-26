#include "Controller.h"
#include <GL\freeglut.h>
#include <Box2D\Box2D.h>

Controller::Controller(Config* config) : view(config), config(config)
{
}


Controller::~Controller()
{
}

void Controller::play(Game* game)
{
	sf::Window *window;
	sf::Event event;
	window = view.getWindow();

	while (game->getStatus() == Config::Status::RUNNING)
	{
		game->step();
		view.prepare();
		view.render(game);

		/* render test lines */
		//view->renderTest();

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
		view.viewportSetup();
		break;
	case sf::Event::KeyPressed:
		manageKeyEvent(e, game);
	default:
		break;
	}
}

void Controller::manageKeyEvent(sf::Event &e, Game *game)
{
	if (e.key.code == config->KEY_UP[Config::Players::PLAYER_1]) {
		printf("up pressed\n");
	}
	else if (e.key.code == config->KEY_DOWN[Config::Players::PLAYER_1]) {
		printf("down pressed\n");
	}
	else if (e.key.code == config->KEY_LEFT[Config::Players::PLAYER_1]) {
		printf("left pressed\n");
	}
	else if (e.key.code == config->KEY_RIGHT[Config::Players::PLAYER_1]) {
		printf("right pressed\n");
	}
	else if (e.key.code == config->KEY_FIRE[Config::Players::PLAYER_1]) {
		printf("enter pressed\n");
		game->shoot(Config::Players::PLAYER_1);
	}
	else if (e.key.code == config->KEY_AP[Config::Players::PLAYER_1]) {
		printf("num8 pressed\n");
		game->getTank(Config::Players::PLAYER_1)->setLoadedShellType(Config::ShellType::AP);
	}
	else if (e.key.code == config->KEY_HE[Config::Players::PLAYER_1]) {
		printf("num9 pressed\n");
		game->getTank(Config::Players::PLAYER_1)->setLoadedShellType(Config::ShellType::HE);
	}
	else if (e.key.code == config->KEY_SH[Config::Players::PLAYER_1]) {
		printf("num0 pressed\n");
		game->getTank(Config::Players::PLAYER_1)->setLoadedShellType(Config::ShellType::SHRAPNEL);
	}
	else if (e.key.code == config->KEY_UP[Config::Players::PLAYER_2]) {
		printf("w pressed\n");
	}
	else if (e.key.code == config->KEY_DOWN[Config::Players::PLAYER_2]) {
		printf("s pressed\n");
	}
	else if (e.key.code == config->KEY_LEFT[Config::Players::PLAYER_2]) {
		printf("a pressed\n");
	}
	else if (e.key.code == config->KEY_RIGHT[Config::Players::PLAYER_2]) {
		printf("d pressed\n");
	}
	else if (e.key.code == config->KEY_FIRE[Config::Players::PLAYER_2]) {
		printf("space pressed\n");
		game->shoot(Config::Players::PLAYER_2);
	}
	else if (e.key.code == config->KEY_AP[Config::Players::PLAYER_2]) {
		printf("num1 pressed\n");
		game->getTank(Config::Players::PLAYER_2)->setLoadedShellType(Config::ShellType::AP);
	}
	else if (e.key.code == config->KEY_HE[Config::Players::PLAYER_2]) {
		printf("num2 pressed\n");
		game->getTank(Config::Players::PLAYER_2)->setLoadedShellType(Config::ShellType::HE);
	}
	else if (e.key.code == config->KEY_SH[Config::Players::PLAYER_2]) {
		printf("num3 pressed\n");
		game->getTank(Config::Players::PLAYER_2)->setLoadedShellType(Config::ShellType::SHRAPNEL);
	}
	else if (e.key.code == config->KEY_QUIT) {
		game->setStatus(Config::Status::FINISHED);
	}
}
