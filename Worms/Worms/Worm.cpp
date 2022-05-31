#include "Worm.h"

void Worm::Update()
{
	State->Update();
	ObjectState *nxt = State->GetNext();
	if (nxt)
	{
		State = nxt;
	}

	// Calc collisions with map
	CalculateCollisionX();
	CalculateCollisionY();
	// move with collisions
	Move();

	if (collision_y)
		dy += 1. / 6;
	else
		dy = 0;
	dy = 0;

	direction = dx > 0 ? true : dx < 0 ? false : direction;
	dx = 0;
}

void Worm::Show(sf::RenderWindow * window, long long lag)
{
	Singleton *single = Singleton::GetInstance();

	CurrentSprite = sprites[LastSpriteNumber];

	CurrentSprite.setPosition(
		window_pos_X - single->game_mouse_position_x,
		window_pos_Y - single->game_mouse_position_y
	);

	window->draw(CurrentSprite);
}

Worm::Worm(float x, float y, GameMap *n_map) : PlayableObject(x, y, n_map)
{
	Width = 30;
	Height = 30;

	GeneratePosition(window_pos_X, window_pos_Y);
	last_stabil_x = window_pos_X;
	last_stabil_y = window_pos_Y;

	sf::RectangleShape rectangle(sf::Vector2f(Width, Height));
	rectangle.setFillColor(sf::Color::Red);

	AnimationSteps = 3;

	LoadSprite("Textures/GameObjects/Worm/Walk1.png");
	LoadSprite("Textures/GameObjects/Worm/Walk2.png");
	LoadSprite("Textures/GameObjects/Worm/Walk3.png");
	LoadSprite("Textures/GameObjects/Worm/Jump.png");

	LastSpriteNumber = 0;

	State = new WaitWormState(this);
}

void Worm::digSpace(int x, int y)
{
	int n = map->Width;
	int m = map->Height;

	int Radius = 50;

	for (int i = x - Radius; i <= x + Radius; i++)
		for (int j = y - Radius; j <= y + Radius; j++)
		{
			if (i < 0 || j < 0 || i > n || j > m)
				continue;

			int tx = x - i;
			int ty = y - j;

			if (tx*tx + ty * ty < Radius * Radius)
			{
				map->pixels[x][y] = false;
				map->map[(i + j * int(n)) * 4] = 150; // R?
				map->map[(i + j * int(n)) * 4 + 1] = 150; // G?
				map->map[(i + j * int(n)) * 4 + 2] = 255; // B?
				map->map[(i + j * int(n)) * 4 + 3] = 255; // A?
			}
		}
}

void Worm::GeneratePosition(float & x, float & y)
{
	int n = map->Width;
	int m = map->Height;

	x = rand() % n;

	bool find = false;

	for (y = 10; y <= m - 40; y++)
	{
		if (isStable())
		{
			find = true;
			break;
		}
	}

	if (!find)
	{
		y = rand() % (m - 50) + 10;
		digSpace(x, y);
	}

	return;
}
