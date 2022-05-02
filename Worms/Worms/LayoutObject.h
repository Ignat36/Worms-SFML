#pragma once

#include <string>
#include <SFML/Graphics.hpp>

class LayoutObject
{
public:
	bool HidenFromUser;
	// window position / Rect 
	std::string Name;
	std::string Text;
	int ObjectId;

public:
	virtual void Show(sf::RenderWindow *window) = 0;
	LayoutObject(int id);
};

