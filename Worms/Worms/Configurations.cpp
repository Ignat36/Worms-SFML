#include "Configurations.h"

Configurations::Configurations(std::string file)
{
	if (file == "")
	{
		game_config = new GameConfigurations();
		map = new GameMap();
		teams = new TeamsConfigurations();
		weapons = new WeaponConfigurations();
	}
}
