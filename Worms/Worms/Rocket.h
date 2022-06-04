#pragma once

#include "Ammo.h"

class Rocket : public Ammo
{
public:
	void Update() override;
	void Show(sf::RenderWindow *window, long long lag = 0) override;
	Rocket();
};

