#include "GameState.h"
#include "Singleton.h"

GameState::GameState(sf::RenderWindow * window, long long *_lag) : 
	ApplicationState(window),
	CurrentInventory(&InventoryA),
	CurrentTeam(&TeamA)
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

	for (int i = 0; i < single->config.teams->TeamACount; i++)
	{
		TeamA.push_back(new Worm(0, 0, map, true));
		TeamA.back()->inventory = &InventoryA;
	}

	for (int i = 0; i < single->config.teams->TeamBCount; i++)
	{
		TeamB.push_back(new Worm(0, 0, map, false));
		TeamB.back()->inventory = &InventoryB;
	}

	team = abs(rand()) % 2;
	UpdateTeam();


	map->FullReRender(); map->UpdateSprite();

	window->setMouseCursorVisible(false);
	CurrentTeam->back()->SetScreenCenter();
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
				CurrentTeam->back()->SetScreenCenter();
				break;
			default:
				CurrentTeam->back()->State->ProcessInput(event);
				break;
			}
		}
		else
		if (event.type == sf::Event::TextEntered)
		{

		}
		else
			CurrentTeam->back()->State->ProcessInput(event);
	}
}

void GameState::UpdateObjects()
{
	UpdateMapPosition();

	UpdateMap();

	GetNewObjects();

	ProcessExplosions();

	UpateTeamesPh(TeamA);
	UpateTeamesPh(TeamB);

	UpdateDynamicObjects();

	EndTurn();
}

void GameState::RenderObjects(sf::RenderWindow * window)
{
	window->clear();

	Singleton::ShowMap(map, window);

	for (auto i : objects)
		i->Show(window, *lag);

	for (auto i : TeamA)
		i->Show(window, *lag);

	for (auto i : TeamB)
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
	if (CheckEnd())
	{
		if (!EndTurnTime.Active())
		{
			EndTurnTime.Start();
			return;
		}

		if (EndTurnTime.Elapsed() < 4)
		{
			return;
		}

		sing->EndTurn = false;
		PlayableObject *tmp = CurrentTeam->back();
		CurrentTeam->pop_back();
		CurrentTeam->push_front(tmp);
		UpdateTeam();

		EndGame();

		CurrentTeam->back()->SetScreenCenter();
	}
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

void GameState::UpdateMap()
{
	if (sing->MapUpdate)
	{
		sing->MapUpdate = false;
		map->UpdateSprite();
	}
}

void GameState::GetNewObjects()
{
	for (auto i : sing->que)
	{
		objects.push_back(i);
		objects.back()->SetGameMap(map);

		std::cout << i->window_pos_X << " " << i->window_pos_Y << "\n";
	}

	sing->que.resize(0);
}

void GameState::ProcessExplosions()
{
	for (auto i : sing->explosions)
	{
		ProcessExplosion(i.first.first, i.first.second, i.second, TeamA);
		ProcessExplosion(i.first.first, i.first.second, i.second, TeamB);
	}

	sing->explosions.resize(0);
}

void GameState::ProcessExplosion(float x, float y, int radius, std::deque<PlayableObject *> &v)
{
	for (auto i : v)
	{
		float wx = i->window_pos_X + i->Width / 2.;
		float wy = i->window_pos_Y + i->Height / 2.;
		float wr = i->Height / 2.;

		float dist = sqrt(
			(x - wx) * (x - wx) +
			(y - wy) * (y - wy)
		);

		if (dist >= wr + radius)
			continue;

		float strength = sqrt(wr + radius - dist) * 2;
		strength = strength > 20 ? 20: strength;
		strength = strength < 5 ? 5: strength;

		float alpha = atan(abs(y - wy) / abs(x - wx));

		//alpha = alpha * 180 / 3.1415;

		float ndx = strength * cos(alpha);
		float ndy = strength * sin(alpha);

		if (x > wx)
			ndx = -ndx;

		if (y > wy)
			ndy = -ndy;

		i->push(ndx, ndy);
	}
}

void GameState::UpdateTeam()
{
	if (team)
		team = false;
	else
		team = true;

	if (team)
	{
		CurrentTeam = &TeamA;
		CurrentInventory = &InventoryA;
	}
	else
	{
		CurrentTeam = &TeamB;
		CurrentInventory = &InventoryB;
	}
}

void GameState::UpateTeamesPh(std::deque<PlayableObject*> &t)
{
	std::deque<PlayableObject*> UpTeam;
	for (auto i : t)
	{
		i->Update();
		if (!i->isDead())
			UpTeam.push_back(i);
	}

	t = UpTeam;
}

void GameState::UpdateDynamicObjects()
{
	std::vector<DynamicObject *> tmp;
	for (auto i : objects)
	{
		i->Update();
		if (!i->isDead())
		{
			std::cout << i->window_pos_X << " " << i->window_pos_Y << "\n";
			tmp.push_back(i);
		}
		else
			delete i;
	}
	objects = tmp;
}

bool GameState::CheckEnd()
{
	if (!sing->EndTurn)
		return false;

	for (auto i : TeamA)
		if (i->NoActionFrames < 240)
			return false;

	for (auto i : TeamB)
		if (i->NoActionFrames < 240)
			return false;

	for (auto i : objects)
		if (i->NoActionFrames < 240)
			return false;

	return true;
}
