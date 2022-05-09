#pragma once

#include "ApplicationState.h"
#include "TurnState.h"

class GameState : public ApplicationState
{
public:
	GameState(sf::RenderWindow *window);

public:
	void ProcessInput(sf::RenderWindow *window) override;
	void UpdateObjects() override;
	void RenderObjects(sf::RenderWindow *window) override;

private:
	std::vector<TurnState *> CurrentState;

	bool isButtonPressed;
};

