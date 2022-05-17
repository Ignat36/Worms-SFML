#pragma once

#include "PlayableObject.h"

class Worm : public PlayableObject
{
public:
	void Update() override;
	void Show(sf::RenderWindow *window, long long lag = 0) override;

public:
	Worm(float x, float y, std::vector<std::vector<bool> > *n_map);

private:
	sf::Text Name;
	int HealthPoints;
};

