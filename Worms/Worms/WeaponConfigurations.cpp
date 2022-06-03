#include "WeaponConfigurations.h"

WeaponConfigurations::WeaponConfigurations()
{
	Count = 1;
	Power.resize(Count);
	BoxChance.resize(Count);
	Uses.resize(Count);
	TurnLimit.resize(Count);
	BoxAdditionalUses.resize(Count);

	for (int i = 0; i < Count; i++)
	{
		Power[i] = 10;
		BoxChance[i] = (100 / Count);
		Uses[i] = 4;
		TurnLimit[i] = 0;
		BoxAdditionalUses[i] = bounds(1, 2);
	}
}
