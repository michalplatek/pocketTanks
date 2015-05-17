#include "Config.h"


Config::Config(int argc, char** argv)
{
	WINDOW_X = 100;
	WINDOW_Y = 100;
	WINDOW_W = 1280;
	WINDOW_H = 720;
	ARGC = argc;
	ARGV = argv;

	WINDOW_DEPTH_BITS = 24;
	WINDOW_STENCIL_BITS = 8;
	WINDOW_ANTIALIASING_LEVEL = 4;
	WINDOW_MAJOR_VERSION = 3;
	WINDOW_MINOR_VERSION = 0;

	BOX2D_POSITION_ITERATIONS = 2;
	BOX2D_VELOCITY_ITERATIONS = 6;
	BOX2D_TIME_STEP = 1.0f / 30.0f;

	NUM_PLAYERS = 2;
	TANKS_PER_PLAYER = 1;
	NUM_TANKS = NUM_PLAYERS * TANKS_PER_PLAYER;
	GRAVITY = -1.0f;

	KEY_PLAYER1_UP = sf::Keyboard::Up;
	KEY_PLAYER1_DOWN = sf::Keyboard::Down;
	KEY_PLAYER1_LEFT = sf::Keyboard::Left;
	KEY_PLAYER1_RIGHT = sf::Keyboard::Right;
	KEY_PLAYER1_FIRE = sf::Keyboard::Return;
	KEY_PLAYER2_UP = sf::Keyboard::W;
	KEY_PLAYER2_DOWN = sf::Keyboard::S;
	KEY_PLAYER2_LEFT = sf::Keyboard::A;
	KEY_PLAYER2_RIGHT = sf::Keyboard::D;
	KEY_PLAYER2_FIRE = sf::Keyboard::Space;
	KEY_QUIT = sf::Keyboard::Escape;
}


Config::~Config()
{
}
