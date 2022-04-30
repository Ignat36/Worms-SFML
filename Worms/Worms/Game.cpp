#include "Game.h"

Game::Game()
{
	ScreenWidth = 400;
	ScreenHeight = 400;
	MKS_PER_UPDATE = 16667;
	single = Singleton::GetInstance();
	lag = 0;
}

void Game::Start()
{
	sf::CircleShape shape(100.f);

	window = new sf::RenderWindow(sf::VideoMode(ScreenWidth, ScreenHeight), "WORMS");

	auto start = std::chrono::high_resolution_clock::now();

	while (window->isOpen())
	{

		auto stop = std::chrono::high_resolution_clock::now();
		long long elapsed = (std::chrono::duration_cast<std::chrono::microseconds>(stop - start)).count();
		lag += elapsed;

		GameLoop();
	}
}



void Game::GameLoop()
{
	//input processing
	CurrentState->ProcessInput();
	
	while (lag >= MKS_PER_UPDATE)
	{
		CurrentState->UpdateObjects();
		lag -= MKS_PER_UPDATE;
	}

	CurrentState->RenderObjects();
}
