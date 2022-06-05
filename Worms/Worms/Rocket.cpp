#include "Rocket.h"
#include "Singleton.h"
#include <cmath>

void Rocket::Update()
{
	Move(1);

	dy += 1. / 6.;

	last_stabil_x = window_pos_X;
	last_stabil_y = window_pos_Y;

	if (!collisionVariable)
	{
		isAlive = false;
		push_x = 0;
		push_y = 0;
		Explode(window_pos_X, window_pos_Y);
		sing->explosions.push_back({ {window_pos_X, window_pos_Y}, sing->config.weapons->Power[id] * 10 });
	}

	if (push_x || abs(dy) > 2) NoActionFrames = 0;
	else NoActionFrames++;
}

void Rocket::Show(sf::RenderWindow * window, long long lag)
{

	float alpha = atan(abs(dy) / abs(push_x));

	alpha = alpha * 180 / 3.1415;

	if (push_x < 0)
		alpha = 180 - alpha;

	if (dy <= 0)
		alpha = -alpha;

	Singleton *single = Singleton::GetInstance();

	CurrentSprite = sprites[LastSpriteNumber];

	CurrentSprite->setPosition(
		window_pos_X - single->game_mouse_position_x,
		window_pos_Y - single->game_mouse_position_y
	);

	CurrentSprite->setOrigin(Width / 2., Height / 2.);

	CurrentSprite->setRotation(alpha);

	window->draw(*CurrentSprite);
}

Rocket::Rocket()
{
	Width = 5;
	Height = 5;

	AnimationSteps = 1;

	LoadSprite("Textures/Weapons/Rocket.png");

	LastSpriteNumber = 0;

	FPS = 60;
	CurrentFrame = 0;
	ChangesPerSecond = 0;
	NoActionFrames = 0;

	id = 0;
}
