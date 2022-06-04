#include "Rocket.h"
#include "Singleton.h"

void Rocket::Update()
{
	Move(1);

	last_stabil_x = window_pos_X;
	last_stabil_y = window_pos_Y;

	if (collisionVariable)
	{
		isAlive = false;
		push_x = 0;
		push_y = 0;
		Explode(window_pos_X, window_pos_Y);
	}
}

void Rocket::Show(sf::RenderWindow * window, long long lag)
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

	window->draw(*CurrentSprite);
}

Rocket::Rocket()
{
	Width = 30;
	Height = 20;

	AnimationSteps = 1;

	LoadSprite("Textures/Weapons/Rocket.png");

	LastSpriteNumber = 0;

	FPS = 60;
	CurrentFrame = 0;
	ChangesPerSecond = 0;

	id = 0;
}
