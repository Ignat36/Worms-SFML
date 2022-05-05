#pragma once

#include <vector>

class GameMap
{
public:
	static GameMap Random(); // opens rundom basic map
	std::vector<std::vector<bool> > pixels;
};

