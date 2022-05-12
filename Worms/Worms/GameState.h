#pragma once

#include <deque>

#include "ApplicationState.h"
#include "PlayableObject.h"

class GameState : public ApplicationState
{
public:
	GameState(sf::RenderWindow *window, long long *_lag);

public:
	void ProcessInput(sf::RenderWindow *window) override;
	void UpdateObjects() override;
	void RenderObjects(sf::RenderWindow *window) override;

private:

	std::deque<PlayableObject *> Playables;
	std::vector<GameObject *> objects;
	bool isButtonPressed;

	long long *lag;

private:
	void EndRound();
	void EndGame();
	void EndTurn();
};

