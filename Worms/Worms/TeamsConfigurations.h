#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <ctime>


class TeamsConfigurations
{
public:
	int TeamACount;
	int TeamBCount;
	std::vector<std::string> TeamANames;
	std::vector<std::string> TeamBNames;

public:
	TeamsConfigurations(int n = 8, int m = 8);
};

