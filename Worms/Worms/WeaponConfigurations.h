#pragma once

#include <string>
#include <vector>


class WeaponConfigurations
{
public:
	WeaponConfigurations();
private:
	struct bounds
	{
		int left;
		int right;

		bounds(int n_left, int n_right) : 
			left(n_left), right(n_right) {}

		bounds() : left(1), right(2) {}
	};

public:
	int Count;
	std::vector<int> Power; // 10 max
	std::vector<int> BoxChance; // of 100
	std::vector<int> Uses; // 10 max of -1 then infinity
	std::vector<int> TurnLimit; 
	std::vector<bounds> BoxAdditionalUses; // 10 max 1 min
};

