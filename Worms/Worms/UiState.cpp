#include "UiState.h"

UiState::UiState()
{
	CurrentLayout.push_back(new MainMenuLayout());
}

void UiState::ProcessInput(sf::RenderWindow * window)
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			Singleton *single = Singleton::GetInstance();
			single->WindowClosed = true;
			break;
		}

		if (event.type == sf::Event::MouseButtonPressed)
		{
			// Search srough layout description and current mouse position 
			// Update if exists pressed field LayoutObject id
		}

		if (event.type == sf::Event::KeyPressed)
		{
			// put symobl into buffer if exists
			// if enter submit buffer
		}
	}
}
