#pragma once

#include "PlayableObject.h"

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


private:
	void digSpace(int x, int y);
	void GeneratePosition(float &x, float &y);
};

