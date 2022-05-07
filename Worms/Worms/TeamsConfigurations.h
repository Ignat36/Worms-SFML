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
	TeamsConfigurations(int n = 5, int m = 5);
};

