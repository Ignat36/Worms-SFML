#include "GameState.h"
#include "Singleton.h"

GameState::GameState(sf::RenderWindow * window, long long *_lag) : ApplicationState(window)
{
	// black part of scheme
	lag = _lag;
	Singleton *single = Singleton::GetInstance(); 

	InventoryA = *(single->config.weapons);
	InventoryB = *(single->config.weapons);

	map = single->config.map;

	if (!map->image.loadFromFile(single->GlobalPath + "Maps/Background/Background.png"))
	{
		std::cout << "Can not read from file game background\n";
		single->WindowClosed = true;
		return;
	}

	map->pixels = GameMap::Load("D:\\Windows\\Worms-SFML\\Worms\\Worms\\Maps\\Standart\\Map0.txt").pixels;
	map->Width = 1200; map->Height = 400;
	map->DefaultMap = (sf::Uint8 *)map->image.getPixelsPtr();
	map->Expand(); 

	Playables.push_back(new Worm(0, 0, map));
	Playables.back()->inventory = &InventoryA;


	map->FullReRender(); map->UpdateSprite();

	window->setMouseCursorVisible(false);
	Playables.back()->SetScreenCenter();
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
			case sf::Keyboard::Delete:
				window->setMouseCursorVisible(true);
				StateChangeFlag = true;
				break;
			case sf::Keyboard::RControl:
				Playables.back()->SetScreenCenter();
				break;
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


	for (auto i : sing->que)
	{
		objects.push_back(i);
	}

	sing->que.resize(0);


	Playables.back()->Update();
	if (Playables.back()->isDead())
	{
		Playables.pop_back();
		if (Playables.empty())
			EndRound();
	}

	std::vector<DynamicObject *> tmp;
	for (auto i : objects)
	{
		if (!i->isDead())
			tmp.push_back(i);
		else
			delete i;
	}
	objects = tmp;

}

void GameState::RenderObjects(sf::RenderWindow * window)
{
	window->clear();

	Singleton::ShowMap(map, window);

	for (auto i : objects)
		i->Show(window, *lag);

	for (auto i : Playables)
		i->Show(window, *lag);

	window->display();
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

	int tw = map->Width;
	int th = map->Height;

	if (abs(ax) + abs(ay) > 1)
	{
		g_p_y += ay;
		g_p_x += ax;

		if (g_p_x > tw - w) g_p_x = tw - w;
		if (g_p_x < 0) g_p_x = 0;

		if (g_p_y > th - h) g_p_y = th - h;
		if (g_p_y < 0) g_p_y = 0;
	}
}
