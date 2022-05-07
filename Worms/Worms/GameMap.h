#pragma once

#include <vector>
#include <string>
#include <fstream>

class GameMap
{
public:
	GameMap(); // opens rundom basic map
	std::vector<std::vector<bool> > pixels;

	int Width = 6000;
	int Height = 2000;
};

