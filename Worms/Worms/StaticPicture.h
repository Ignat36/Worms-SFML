#pragma once

#include <SFML/Graphics.hpp>

#include "LayoutObject.h"

class StaticPicture : public LayoutObject
{
public:
	void Show(sf::RenderWindow *window) override;
	StaticPicture(int id);
};

