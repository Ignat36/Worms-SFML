#include "GameMap.h"

GameMap::GameMap()
{
	Height = 2000;
	Width = 6000;
	pixels.resize(Height);
	std::string path = "Maps/Standart/map" + std::to_string(rand() % 1) + ".txt";
	std::ifstream fin(path); fin.open("r");
	std::string str;
	int i = 0;
	while (fin >> str)
	{
		pixels[i++].resize(Width);
		for (int j = 0; j < str.size(); j++)
			pixels[i][j] = str[j] == '1';
	}
}
