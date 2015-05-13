#ifndef _CONFIG_H_
#define _CONFIG_H_

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
	int BOX2D_TIME_STEP;
	/* game settings */
	int NUM_PLAYERS;
	int TANKS_PER_PLAYER;
	int NUM_TANKS;
	float GRAVITY;
	enum class Status { RUNNING, FINISHED };

	Config(int argc, char** argv);
	~Config();
};

#endif