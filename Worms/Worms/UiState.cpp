#include "UiState.h"

UiState::UiState(sf::RenderWindow *window) : ApplicationState()
{
	CurrentLayout.push_back(new MainMenuLayout(window));
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

		if (event.type == sf::Event::MouseButtonPressed &&
			event.mouseButton.button == sf::Mouse::Left)
		{
			// Search srough layout description and current mouse position 
			// Update if exists pressed field LayoutObject id
			CurrentLayout.back()->Update(window);
		}

		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::BackSpace:
				CurrentLayout.back()->EraseLastCharacterFromBuffer();
				break;

			case sf::Keyboard::Enter:
				CurrentLayout.back()->ConfirmBuffer();
				break;

			default:
				break;
			}
		}

		if (event.type == sf::Event::TextEntered)
		{
			if (event.text.unicode < 128)
				CurrentLayout.back()->AddCharacterToBuffer(static_cast<char>(event.text.unicode));
		}
	}
}

void UiState::UpdateObjects()
{
	// UI objects don't have phisic part
	
	if (CurrentLayout.back()->ChangeLayout())
	{
		Layout *transition = CurrentLayout.back()->getNextLayout();
		if (transition)
			CurrentLayout.push_back(transition);
		else
		{
			CurrentLayout.pop_back();

			if (CurrentLayout.empty()) {
				StateChangeFlag = true;
			}
		}
	}
		
}

void UiState::RenderObjects(sf::RenderWindow * window)
{
	// Show Layout
	window->clear();
	CurrentLayout.back()->Show(window);
	window->display();
}
