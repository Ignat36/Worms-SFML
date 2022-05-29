#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>

class GameMap
{
public:
	GameMap(); // opens rundom basic map
	std::vector<std::vector<bool> > pixels;

	int Width = 6000;
	int Height = 2000;

	sf::Uint8 *map;
	sf::Uint8 *DefaultMap;
	sf::Image image;
	sf::Image CurrentMapImage;
	sf::Texture CurrentMapTexture;
	sf::Sprite CurrentMapSprite;

public:
	void Expand();
	void UpdateSprite();
	void FullReRender();
};

