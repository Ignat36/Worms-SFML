#pragma once

#include <SFML/Graphics.hpp>
#include <ctime>
#include <chrono>

#include "WindowState.h"
#include "Singleton.h"

typedef long double ld;

class Game
{
public:
	void Start();
	Game();

private:
	GameState *CurrentState;
	Singleton *single;

	int ScreenWidth;
	int ScreenHeight;
	sf::RenderWindow *window;
	long long MKS_PER_UPDATE;

private: // logic functions
	void GameLoop();

};

