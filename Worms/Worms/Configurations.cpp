#include "Configurations.h"

Configurations::Configurations(std::string file)
{
	if (file == "")
	{
		game_config = GameConfigurations();
		map = GameMap::Random();
		teams = TeamsConfigurations();
		weapons = WeaponConfigurations();
	}
}
