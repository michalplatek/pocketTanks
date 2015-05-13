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

	Config(int argc, char** argv);
	~Config();
};

#endif