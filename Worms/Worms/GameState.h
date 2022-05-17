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
	std::vector<GameObject *> objects;
	bool isButtonPressed;

	long long *lag;

	std::vector<std::vector<bool> > pixels;
	sf::Uint8 *map;
	sf::Image image;
	sf::Image CurrentMapImage;
	sf::Texture CurrentMapTexture;
	sf::Sprite CurrentMapSprite;

private:
	void UpdateTexture();
	void EndRound();
	void EndGame();
	void EndTurn();
};

