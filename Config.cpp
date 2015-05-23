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
	GRAVITY = -9.8f;
	LEVEL_SIZE_IN_METRES = 200.0f;

	KEY_UP[Players::PLAYER_1] = sf::Keyboard::Up;
	KEY_DOWN[Players::PLAYER_1] = sf::Keyboard::Down;
	KEY_LEFT[Players::PLAYER_1] = sf::Keyboard::Left;
	KEY_RIGHT[Players::PLAYER_1] = sf::Keyboard::Right;
	KEY_FIRE[Players::PLAYER_1] = sf::Keyboard::Return;
	KEY_UP[Players::PLAYER_2] = sf::Keyboard::W;
	KEY_DOWN[Players::PLAYER_2] = sf::Keyboard::S;
	KEY_LEFT[Players::PLAYER_2] = sf::Keyboard::A;
	KEY_RIGHT[Players::PLAYER_2] = sf::Keyboard::D;
	KEY_FIRE[Players::PLAYER_2] = sf::Keyboard::Space;

	START_POSITION_X[Players::PLAYER_1] = 50.0f;
	START_POSITION_Y[Players::PLAYER_1] = 50.0f;
	START_ROTATION[Players::PLAYER_1] = -30.0f;
	START_GUN_ANGLE[Players::PLAYER_1] = 45.0f;

	START_POSITION_X[Players::PLAYER_2] = 150.0;
	START_POSITION_Y[Players::PLAYER_2] = 50.0f;
	START_ROTATION[Players::PLAYER_2] = 30.0f;
	START_GUN_ANGLE[Players::PLAYER_2] = -45.0f;

	KEY_QUIT = sf::Keyboard::Escape;
}


Config::~Config()
{
}

float Config::positionToPixel(float position)
{
	float ratio = WINDOW_W / LEVEL_SIZE_IN_METRES;
	return position * ratio;
}
