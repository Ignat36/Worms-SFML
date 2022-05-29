#include "GameState.h"

GameState::GameState(sf::RenderWindow * window, long long *_lag) : ApplicationState(window)
{
	// black part of scheme
	lag = _lag;
	Singleton *single = Singleton::GetInstance();
	map = single->config.map;

	if (!map->image.loadFromFile("Maps/Background/Background.png"))
	{
		std::cout << "Can not read from file game background\n";
		single->WindowClosed = true;
		return;
	}

	map->DefaultMap = (sf::Uint8 *)map->image.getPixelsPtr();
	map->FullReRender(); map->UpdateSprite();

	Playables.push_back(new Worm(0, 0, map));
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
				Playables.back()->State->ProcessInput(event);
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
	UpdateMapPosition();

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

void GameState::EndRound()
{
}

void GameState::EndGame()
{
}

void GameState::EndTurn()
{
}

void GameState::UpdateMapPosition()
{
	Singleton *single = Singleton::GetInstance();

	int &g_p_x = single->game_mouse_position_x;
	int &g_p_y = single->game_mouse_position_y;

	int x = sf::Mouse::getPosition(*window).x;
	int y = sf::Mouse::getPosition(*window).y;

	int w = window->getSize().x;
	int h = window->getSize().y;

	sf::Mouse::setPosition(sf::Vector2i(w/2, h/2), *window);

	int ax = x - w / 2;
	int ay = y - h / 2;

	if (abs(ax) + abs(ay) > 1)
	{
		g_p_y += ay;
		g_p_x += ax;
	}
}
