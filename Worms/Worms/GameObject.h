#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Singleton.h"

class GameObject
{
public:
	GameObject();
	GameObject(float x, float y);
	virtual void Show(sf::RenderWindow *window, long long lag = 0) = 0;

	bool isDead();
	bool AddTexture(std::string file);

protected:
	std::vector< sf::Texture> textures;
	std::vector< sf::Sprite> sprites;

	bool isAlive;
	float window_pos_X;
	float window_pos_Y;
};

