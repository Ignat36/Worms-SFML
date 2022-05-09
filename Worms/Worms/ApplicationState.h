#pragma once

#include <SFML/Graphics.hpp>

class ApplicationState
{
public:
	ApplicationState(sf::RenderWindow *window);

public:
	virtual void ProcessInput(sf::RenderWindow *window) = 0;
	virtual void UpdateObjects() = 0;
	virtual void RenderObjects(sf::RenderWindow *window) = 0;

	ApplicationState *getNextState(); // sends next and make it nullptr
	bool ChangeState();

protected:
	ApplicationState *Next;
	bool StateChangeFlag;

	sf::RenderWindow *window;
};

