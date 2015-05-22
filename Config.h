#ifndef _CONFIG_H_
#define _CONFIG_H_

#include<SFML/Window.hpp>

class Config
{
public:
	/* window setup */
	int WINDOW_X;
	int WINDOW_Y;
	int WINDOW_W;
	int WINDOW_H;
	char* WINDOW_TITLE = "Pocket Tanks";
	int ARGC;
	char** ARGV;

	/* sfml contect configuration */
	int WINDOW_DEPTH_BITS;
	int WINDOW_STENCIL_BITS;
	int WINDOW_ANTIALIASING_LEVEL;
	int WINDOW_MAJOR_VERSION;
	int WINDOW_MINOR_VERSION;

	/* box2d object configurations */
	int BOX2D_POSITION_ITERATIONS;
	int BOX2D_VELOCITY_ITERATIONS;
	float BOX2D_TIME_STEP;

	/* game settings */
	int NUM_PLAYERS;
	int TANKS_PER_PLAYER;
	int NUM_TANKS;
	float GRAVITY;
	float LEVEL_SIZE_IN_METRES;
	enum class Status { RUNNING, FINISHED };
	enum Players { PLAYER_1, PLAYER_2 };
	
	int KEY_UP[2];
	int KEY_DOWN[2];
	int KEY_LEFT[2];
	int KEY_RIGHT[2];
	int KEY_FIRE[2];
	int KEY_QUIT;
	float START_POSITION_X[2];
	float START_POSITION_Y[2];
	float START_ROTATION[2];
	float START_GUN_ANGLE[2];

	Config(int argc, char** argv);
	~Config();

	float positionToPixel(float position);
};

#endif