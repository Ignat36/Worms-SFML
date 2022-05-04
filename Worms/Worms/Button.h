#pragma once

#include "LayoutObject.h"

class Button : public LayoutObject
{
public:
	void Show(sf::RenderWindow *window) override;
	Button(int id, float pos_x, float pos_y, float width, float height, std::string ButtonFile, std::string CoveredButtonFile);
private:
	sf::Sprite ButtonSprite, CoveredButtonSprite;
	sf::Texture ButtonTexture, CoveredButtonTexture;
};

