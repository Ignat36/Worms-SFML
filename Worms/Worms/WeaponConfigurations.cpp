#include "WeaponConfigurations.h"

WeaponConfigurations::WeaponConfigurations()
{
	Count = 1;
	Power.resize(Count);
	BoxChance.resize(Count);
	Uses.resize(Count);
	TurnLimit.resize(Count);
	BoxAdditionalUses.resize(Count);

	for (auto i : Power) 
		i = 1;
	
	for (auto i : BoxChance)
		i = 1;
	
	for (auto i : Uses)
		i = 4;
	
	for (auto i : TurnLimit)
		i = 0;
	
	for (auto i : BoxAdditionalUses)
		i = bounds(1, 2);
	
}
