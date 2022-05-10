#include "GameState.h"

GameState::GameState(sf::RenderWindow * window, long long *_lag) : ApplicationState(window)
{
	// black part of scheme
	lag = _lag;
}

void GameState::ProcessInput(sf::RenderWindow * window)
{
	Playables.back()->State->ProcessInput(window);
}

void GameState::UpdateObjects()
{
	Playables.back()->Update();
	if (!Playables.back()->isDead())
	{
		Playables.pop_back();
		if (Playables.empty())
			EndRound();
	}

	std::vector<GameObject *> tmp;
	for (auto i : objects)
	{
		if (!i->isDead())
			tmp.push_back(i);
	}
	objects = tmp;
}

void GameState::RenderObjects(sf::RenderWindow * window)
{
}
