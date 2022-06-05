#pragma once

#include <deque>

#include "ApplicationState.h"
#include "PlayableObject.h"
#include "Worm.h"

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

	std::deque<PlayableObject *> TeamA;
	std::deque<PlayableObject *> TeamB;

	WeaponConfigurations InventoryA;
	WeaponConfigurations InventoryB;

	std::vector<DynamicObject *> objects;
	bool isButtonPressed;

	long long *lag;

	GameMap *map;

private:
	void EndRound();
	void EndGame();
	void EndTurn();

	void UpdateMapPosition();
	void UpdateMap();
	void GetNewObjects();
	void ProcessExplosions();
	void ProcessExplosion(float x, float y, int radius);
};

