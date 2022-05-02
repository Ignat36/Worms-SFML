#pragma once

#include <SFML/Graphics.hpp>
#include <ctime>
#include <chrono>

#include "UiState.h"
#include "Singleton.h"

typedef long double ld;

class Game
{
public:
	void Start();
	Game();

private:
	std::vector<ApplicationState*> CurrentState;
	Singleton *single;

	int ScreenWidth;
	int ScreenHeight;
	sf::RenderWindow *window;
	long long MKS_PER_UPDATE;
	long long lag;

private: // logic functions
	void GameLoop();
	void CloseGame();
};

