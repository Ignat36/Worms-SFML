#pragma once

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Singleton.h"

class LayoutObject
{
public:
	bool HidenFromUser;
	// window position / Rect 
	std::string Name;
	std::string Text;
	int ObjectId;

	sf::Vector2f Position;
	sf::Vector2f Size;
	sf::FloatRect Rect;

public:
	virtual void Show(sf::RenderWindow *window) = 0;
	LayoutObject(int id, float pos_x, float pos_y, float width, float height);
protected:
	void LoadSprite(sf::Texture &texture, sf::Sprite &sprite, std::string &file);
};

