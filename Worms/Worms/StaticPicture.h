#pragma once

#include <SFML/Graphics.hpp>

#include "LayoutObject.h"

class StaticPicture : public LayoutObject
{
public:
	void Show(sf::RenderWindow *window) override;
	StaticPicture(int id, float pos_x, float pos_y, float width, float height, std::string PictureFile);

private:
	sf::Texture Texture;
	sf::Sprite Picture;
};

