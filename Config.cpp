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
}


Config::~Config()
{
}
