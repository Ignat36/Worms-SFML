#pragma once

#include "LayoutObject.h"

class Button : public LayoutObject
{
public:
	void Show(sf::RenderWindow *window) override;
	Button(int id);
};

