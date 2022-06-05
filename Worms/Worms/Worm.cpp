#include "Worm.h"
#include "Singleton.h"

void Worm::Update()
{
	State->Update();
	ObjectState *nxt = State->GetNext();
	if (nxt)
	{
		delete State;
		State = nxt;
	}

	// move with collisions
	Move(15);

	last_stabil_x = window_pos_X;
	last_stabil_y = window_pos_Y;

	if (collision_y == 1)
	{
		dy += 1. / 6.;

		if (abs(dy) > 2 && isAnimated == false)
		{
			isAnimated = true;
			push_x += dx;
		}
	}
	else
	{
		dy = 0;
		if(collision_y == 0) isAnimated = false;
		collision_y = 0;

		push_x = 0;
	}

	if (!isAnimated && dx)
	{
		LastSpriteNumber += CurrentFrame / (FPS / ChangesPerSecond);
		LastSpriteNumber %= AnimationSteps;
		CurrentFrame %= (FPS / ChangesPerSecond + 1);
	}
	
	if (isAnimated && abs(dy) > 2)
	{
		LastSpriteNumber = AnimationSteps;
	}

	if (!dx && !dy && CurrentFrame >= 10)
	{
		LastSpriteNumber = 0;
	}

	CurrentFrame++;
	CurrentFrame %= FPS;

	direction = dx > 0 ? true : dx < 0 ? false : direction;

	if (dx || abs(dy) > 2) NoActionFrames = 0;
	else NoActionFrames++;

	dx = 0;
}

void Worm::Show(sf::RenderWindow * window, long long lag)
{
	Singleton *single = Singleton::GetInstance();

	CurrentSprite = sprites[LastSpriteNumber];

	CurrentSprite->setPosition(
		window_pos_X - single->game_mouse_position_x,
		window_pos_Y - single->game_mouse_position_y
	);

	if (direction) CurrentSprite->setOrigin(Width, 0);
	else		   CurrentSprite->setOrigin(0, 0);

	CurrentSprite->setScale(direction ? -1 : 1, 1);

	Name.setPosition(
		window_pos_X - single->game_mouse_position_x + Width / 2 - Name.getGlobalBounds().width / 2,
		window_pos_Y - single->game_mouse_position_y - Name.getGlobalBounds().height - 4
	);

	sf::Text health; 
	health.setFont(sing->GlobalFont);
	health.setString(std::to_string(HealthPoints)); 
	health.setFillColor(Name.getFillColor());
	health.setCharacterSize(Name.getCharacterSize());
	health.setPosition(
		window_pos_X - single->game_mouse_position_x + Width / 2 - health.getGlobalBounds().width / 2,
		window_pos_Y - single->game_mouse_position_y - Name.getGlobalBounds().height - health.getGlobalBounds().height - 8
	);

	window->draw(health);
	window->draw(Name);
	window->draw(*CurrentSprite);

	if (!sing->isAnimation && CurrentWeapon && NoActionFrames > FPS)
		CurrentWeapon->Show(window, CurrentSprite->getGlobalBounds(), attack_angle, direction);
}

Worm::Worm(float x, float y, GameMap *n_map, bool team) : PlayableObject(x, y, n_map)
{
	direction = abs(rand()) % 2;
	isAnimated = false;

	Width = 30;
	Height = 30;

	GeneratePosition(window_pos_X, window_pos_Y);
	last_stabil_x = window_pos_X;
	last_stabil_y = window_pos_Y;

	sing->game_mouse_position_x = window_pos_X - 640;
	sing->game_mouse_position_y = window_pos_Y - 400;

	AnimationSteps = 3;

	LoadSprite("Textures/GameObjects/Worm/Walk1.png");
	LoadSprite("Textures/GameObjects/Worm/Walk2.png");
	LoadSprite("Textures/GameObjects/Worm/Walk3.png");
	LoadSprite("Textures/GameObjects/Worm/Jump.png");

	GetName(team);

	LastSpriteNumber = 0;

	FPS = 60;
	CurrentFrame = 0;
	ChangesPerSecond = 6;

	State = new WaitWormState(this);

	HealthPoints = sing->config.game_config->WormHealth;

	CurrentWeaponId = -1;
	CurrentWeapon = nullptr;
}

void Worm::digSpace(int x, int y)
{
	int n = map->Width;
	int m = map->Height;

	int Radius = 50;

	for (int i = x - Radius; i <= x + Radius; i++)
		for (int j = y - Radius; j <= y + Radius; j++)
		{
			if (i < 0 || j < 0 || i >= n || j >= m || (i + j * n) * 4 + 3 >= n * m * 4)
				continue;

			int tx = x - i;
			int ty = y - j;

			if (tx*tx + ty * ty < Radius * Radius)
			{
				map->pixels[i][j] = false;
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

	x = rand() % (n - 2100) + 1030;
	y = rand() % (m/2) + 10;

	int add = -3;

	bool find = false;

	for(; y > Height + 1 && y < m - 1; y+=add)
		if (isStable())
		{
			find = true;
			return;
		}

	if (!find)
	{
		y = rand() % (m - 50) + 10;
		digSpace(x, y);
	}

	return;
}

void Worm::GetName(bool team)
{
	std::string path = sing->GlobalPath + "Configurations/Names.txt";
	std::ifstream fin; fin.open(path);
	std::vector<std::string> names;
	std::string name;
	int i = 0;
	while (fin >> name)
	{
		i++;
		names.push_back(name);
	}

	Name.setFont(sing->GlobalFont);
	Name.setString(sf::String(names[rand() % names.size()]));
	if(team) Name.setFillColor(sf::Color(247, 121, 89)); // light Red
	else	 Name.setFillColor(sf::Color(128, 229, 255));
	Name.setCharacterSize(20);
}
