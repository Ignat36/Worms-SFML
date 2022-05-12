#include "Game.h"

Game::Game()
{
	ScreenWidth = 1280;
	ScreenHeight = 800;
	MKS_PER_UPDATE = 16667;
	single = Singleton::GetInstance();
	lag = 0;

	window = new sf::RenderWindow(sf::VideoMode(ScreenWidth, ScreenHeight), "WORMS");

	CurrentState.push_back(new UiState(window, &lag));
}

void Game::Start()
{
	auto start = std::chrono::high_resolution_clock::now();

	while (window->isOpen())
	{
		auto stop = std::chrono::high_resolution_clock::now();
		long long elapsed = (std::chrono::duration_cast<std::chrono::microseconds>(stop - start)).count();
		start = stop;
		lag += elapsed;

		GameLoop();

		if (single->WindowClosed)
			CloseGame();
	}
}



void Game::GameLoop()
{
	
	CurrentState.back()->ProcessInput(window);
	
	while (lag >= MKS_PER_UPDATE)
	{
		CurrentState.back()->UpdateObjects();
		lag -= MKS_PER_UPDATE;
		
		if (StateChangeIfPossible())
			return;
		
		//std::cout << lag << "\n";
	}

	CurrentState.back()->RenderObjects(window);
}

void Game::CloseGame()
{
	window->close();
}

bool Game::StateChangeIfPossible()
{
	if (CurrentState.back()->ChangeState())
	{
		ApplicationState *transition = CurrentState.back()->getNextState();
		if (transition)
			CurrentState.push_back(transition);
		else
		{
			CurrentState.pop_back();

			if (CurrentState.empty()) {
				single->WindowClosed = true;
			}
		}
		return true;
	}

	return false;
}
