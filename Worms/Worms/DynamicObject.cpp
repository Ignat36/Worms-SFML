#include "DynamicObject.h"
#include "Singleton.h"

void DynamicObject::push(float ndx, float ndy)
{
	push_x += ndx;
	dy += ndy;
}

DynamicObject::DynamicObject() : GameObject()
{
	dx = 0;
	dy = 0;
	push_x = 0;
	push_y = 0;

	attack_angle = 0;

	collision_x = 1;
	collision_y = 1;

	direction = true;
	NoActionFrames = 0;
}

DynamicObject::DynamicObject(float x, float y, GameMap *n_map) : GameObject(x, y)
{
	dx = 0;
	dy = 0;
	push_x = 0;
	push_y = 0;
	map = n_map;

	collision_x = 1;
	collision_y = 1;

	attack_angle = 0;
	direction = true;
	NoActionFrames = 0;
}

void DynamicObject::SetGameMap(GameMap * nmp)
{
	map = nmp;
}

bool DynamicObject::Push(int possible_pixels)
{
	int i = possible_pixels;
	while (i--)
	{
		if (isStable())
			return true;

		window_pos_Y--;
	}

	window_pos_Y = last_stabil_y;

	i = possible_pixels;
	while (i--)
	{
		if (isStable())
			return true;

		window_pos_Y++;
	}

	
	window_pos_X = last_stabil_x;
	window_pos_Y = last_stabil_y;

	return false;
}

void DynamicObject::Move(int pixelsPush)
{
	window_pos_X += collision_x * dx;
	window_pos_X += collision_x * push_x;

	window_pos_Y += collision_y * dy;
	window_pos_Y += collision_y * push_y;

	CalculateCollision();
	CalculateCollisionY(); if (collision_y <= 0) window_pos_Y = last_stabil_y;
	CalculateCollisionX();

	if (!Push(pixelsPush))
	{
		window_pos_X = last_stabil_x;
		window_pos_Y = last_stabil_y;
	}
}

void DynamicObject::CalculateCollisionX()
{
	collision_x = 1;
}

void DynamicObject::CalculateCollisionY()
{
	if (window_pos_X < 0 || window_pos_X + Width >= map->Width ||
		window_pos_Y < 0) {
		collision_y = 1;
		return;
	}

	if (window_pos_Y + Height >= sing->config.game_config->WaterLevel) {
		collision_y = 0; // —табильно фиксируем дауна, чтобы он потом утанул.
		return;
	}

	for (int x = window_pos_X; x < window_pos_X + Width; x++)
	{
		for (int y = window_pos_Y; y < window_pos_Y + Height; y++)
		{
			int tx = x - window_pos_X - Width / 2;
			int ty = y - window_pos_Y - Height / 2;

			float a = Width * Width / 4.;
			float b = Height * Height / 4.;

			if ((tx * tx) / a + (ty * ty) / b > 1)
				continue;

			if (map->pixels[x][y] && (y - window_pos_Y) >= Height / 2.)
			{
				collision_y = 0;
				return;
			}

			if (map->pixels[x][y] && (y - window_pos_Y) <= Height / 2.)
			{
				collision_y = -1;
				return;
			}
		}
	}

	collision_y = 1;
}

void DynamicObject::CalculateCollision()
{
	if (!isStable())
	{
		collisionVariable = 0;
		return;
	}
	
	collisionVariable = 1;
}

bool DynamicObject::isStable()
{
	if (window_pos_X < 0 || window_pos_X + Width >= map->Width ||
		window_pos_Y < 0) {
		return true;
	}

	if (window_pos_Y + Height >= sing->config.game_config->WaterLevel) {
		return true; // —табильно фиксируем дауна, чтобы он потом утанул.
	}

	for (int x = window_pos_X; x < window_pos_X + Width; x++)
	{
		for (int y = window_pos_Y; y < window_pos_Y + Height; y++)
		{
			int tx = x - window_pos_X - Width / 2;
			int ty = y - window_pos_Y - Height / 2;

			float a = Width * Width / 4.;
			float b = Height * Height / 4.;

			if ((tx * tx) / a + (ty * ty) / b > 1)
				continue;

			if (map->pixels[x][y])
			{
				return false;
			}
		}
	}

	return true;
}

void DynamicObject::update_x()
{
	if (collision_x)
	{
		push_x /= 1.5;
	}
	dx = 0;
}

void DynamicObject::update_y()
{
}
