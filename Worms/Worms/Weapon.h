#pragma once

#include "SFML/Graphics.hpp"
#include "Ammo.h"
#include "Singleton.h"

#include <iostream>

class Weapon
{
public:
	Weapon(int id);
	
	void Show(sf::RenderWindow *window, sf::FloatRect worm, int AttackAngle, bool direction);

private:
	Ammo *ammo;
	int WeaponId;
	sf::Texture InHandsTexture;
	sf::Sprite InHandsSprite;

private:
	void LoadSprite(std::string file);
};

