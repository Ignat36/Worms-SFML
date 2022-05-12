#include "UiState.h"

UiState::UiState(sf::RenderWindow *window, long long *_lag) : ApplicationState(window)
{
	CurrentLayout.push_back(new MainMenuLayout(window));
	isButtonPressed = false;
	lag = _lag;
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
			isButtonPressed = true;
			CurrentLayout.back()->PressedMouseButton = event.mouseButton.button == sf::Mouse::Left;
			CurrentLayout.back()->Update(window);
			CurrentLayout.back()->isButtonReleased = false;

		}

		if (event.type == sf::Event::MouseButtonReleased)
		{
			// Search srough layout description and current mouse position 
			// Update if exists pressed field LayoutObject id
			isButtonPressed = false;
			CurrentLayout.back()->isButtonReleased = true;
		}

		if (event.type == sf::Event::MouseMoved && isButtonPressed)
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
	Layout *transition = CurrentLayout.back()->getNextLayout();
	if (CurrentLayout.back()->ChangeLayout())
	{
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
	else  if (transition)
	{
		delete transition;

		StateChangeFlag = true;
		Next = new GameState(window, lag);
	}
		
}

void UiState::RenderObjects(sf::RenderWindow * window)
{
	// Show Layout
	window->clear();
	CurrentLayout.back()->Show(window);
	window->display();
}
