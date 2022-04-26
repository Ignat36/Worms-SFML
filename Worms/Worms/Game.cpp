#include "Game.h"

Game::Game()
{
	ScreenWidth = 400;
	ScreenHeight = 400;
	MKS_PER_UPDATE = 16667;
	single = Singleton::GetInstance();
}

void Game::Start()
{
	sf::CircleShape shape(100.f);

	window = new sf::RenderWindow(sf::VideoMode(ScreenWidth, ScreenHeight), "WORMS");

	auto start = std::chrono::high_resolution_clock::now();
	single->lag = 0;

	while (window->isOpen())
	{

		auto stop = std::chrono::high_resolution_clock::now();
		long long elapsed = (std::chrono::duration_cast<std::chrono::microseconds>(stop - start)).count();
		single->lag += elapsed;

		GameLoop();
	}
}



void Game::GameLoop()
{
	//input processing
	CurrentState->ProcessInput();
	
	while (single->lag >= MS_PER_UPDATE)
	{
		CurrentState->Update();
		single->lag -= MS_PER_UPDATE;
	}

	CurrentState->Render();
}
