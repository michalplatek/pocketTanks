#ifndef _CONFIG_H_
#define _CONFIG_H_

#include<SFML/Window.hpp>
/* unit conversion */
#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f

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

	/* enums */
	enum class BodyType { WORLD, SHELL, TANK };
	enum class FixtureType { WORLD, SHELL, TANK_FRONT, TANK_BACK, TANK_WHEEL, TANK_TURRET, TANK_BARREL };
	enum class ShellType { AP, HE, SHRAPNEL };
	enum class Status { RUNNING, FINISHED };
	enum Players { PLAYER_1, PLAYER_2, NONE };

	/* game settings */
	int NUM_PLAYERS;
	int TANKS_PER_PLAYER;
	int NUM_TANKS;
	float GRAVITY;
	float LEVEL_SIZE_IN_METRES;
	float MAX_HEALTH;
	Config::Players startingPlayer;
	
	/* keyboard configuration */
	int KEY_UP[2];
	int KEY_DOWN[2];
	int KEY_LEFT[2];
	int KEY_RIGHT[2];
	int KEY_FIRE[2];
	int KEY_HE[2];
	int KEY_SH[2];
	int KEY_AP[2];
	int KEY_QUIT;

	/* initial positions and angles */
	float START_POSITION_X[2];
	float START_POSITION_Y[2];
	float START_ROTATION[2];
	float START_GUN_ANGLE[2];

	Config(int argc, char** argv);
	~Config();

	float positionToPixel(float position);
};

#endif