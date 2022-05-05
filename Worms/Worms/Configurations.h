#pragma once

#include <string>

#include "GameConfigurations.h"
#include "GameMap.h"
#include "TeamsConfigurations.h"
#include "WeaponConfigurations.h"

class Configurations
{
public:
	Configurations(std::string file = "");

public:
	GameConfigurations game_config;
	GameMap map;
	TeamsConfigurations teams;
	WeaponConfigurations weapons;
};

