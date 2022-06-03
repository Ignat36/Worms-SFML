#pragma once

#include "PlayableObject.h"
#include "NormalWormState.h"
#include "WaitWormState.h"
#include "Weapon.h"

class Worm : public PlayableObject
{
public:
	void Update() override;
	void Show(sf::RenderWindow *window, long long lag = 0) override;

public:
	Worm(float x, float y, GameMap *n_map);


private:
	sf::Text Name;
	int HealthPoints;
	int CurrentWeaponId;
	Weapon *CurrentWeapon;

private:
	void digSpace(int x, int y);
	void GeneratePosition(float &x, float &y);
	void GetName();
};

