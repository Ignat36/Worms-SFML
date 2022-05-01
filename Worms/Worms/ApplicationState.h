#pragma once

#include <SFML/Graphics.hpp>

class ApplicationState
{
public:
	virtual void ProcessInput(sf::RenderWindow *window) = 0;
	virtual void UpdateObjects() = 0;
	virtual void RenderObjects(sf::RenderWindow *window) = 0;
};

