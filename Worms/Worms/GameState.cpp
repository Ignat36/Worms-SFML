#include "GameState.h"

GameState::GameState(sf::RenderWindow * window, long long *_lag) : ApplicationState(window)
{
	// black part of scheme
	lag = _lag;
	Singleton *single = Singleton::GetInstance();
	pixels = single->config.map->pixels;

	if (!image.loadFromFile("Maps/Background/Background.png"))
	{
		std::cout << "Can not read from file game background\n";
		single->WindowClosed = true;
		return;
	}

	map = (sf::Uint8 *)image.getPixelsPtr();
	UpdateTexture();

	Playables.push_back(new Worm(0, 0, &pixels));
}

void GameState::ProcessInput(sf::RenderWindow * window)
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
		else
		if (event.type == sf::Event::MouseButtonPressed)
		{
			// Search srough layout description and current mouse position 
			// Update if exists pressed field LayoutObject id

		}
		else
		if (event.type == sf::Event::MouseButtonReleased)
		{
			// Search srough layout description and current mouse position 
			// Update if exists pressed field LayoutObject id
		}
		else
		if (event.type == sf::Event::MouseMoved && isButtonPressed)
		{
			// Search srough layout description and current mouse position 
			// Update if exists pressed field LayoutObject id
		}
		else
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			default:
				break;
			}
		}
		else
		if (event.type == sf::Event::TextEntered)
		{

		}
		else
		Playables.back()->State->ProcessInput(event);
	}
	
}

void GameState::UpdateObjects()
{
	Playables.back()->Update();
	if (!Playables.back()->isDead())
	{
		Playables.pop_back();
		if (Playables.empty())
			EndRound();
	}

	std::vector<GameObject *> tmp;
	for (auto i : objects)
	{
		if (!i->isDead())
			tmp.push_back(i);
	}
	objects = tmp;
}

void GameState::RenderObjects(sf::RenderWindow * window)
{
}

void GameState::UpdateTexture()
{
	CurrentMapImage.create(pixels.size(), pixels[0].size(), map);
	CurrentMapTexture.loadFromImage(CurrentMapImage);
	CurrentMapSprite.setTexture(CurrentMapTexture);
	CurrentMapSprite.setPosition(0, 0);
}

void GameState::EndRound()
{
}

void GameState::EndGame()
{
}

void GameState::EndTurn()
{
}
