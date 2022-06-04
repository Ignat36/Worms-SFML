#include "Ammo.h"
#include "Singleton.h"
#include <cmath>

void Ammo::SetPosition(DynamicObject * launcher)
{

	direction = launcher->direction;

	last_stabil_y = window_pos_Y = 

		launcher->window_pos_Y + launcher->Height / 2. -
		35 * sin((launcher->attack_angle) * 3.14 / 180.);

	last_stabil_x = window_pos_X = 

		launcher->window_pos_X + launcher->Width / 2. +
		20 * cos(launcher->attack_angle * 3.14 / 180.) * (direction ? 1 : -1);
}

void Ammo::SetDirection(float angle)
{
	push_x = 25 * cos(angle * 3.14 / 180.) * (direction ? 1 : -1);
	dy = -20 * sin(angle * 3.14 / 180.);
}

void Ammo::SetStrength(float part)
{
	push_x *= part;
	dy *= part;
}

void Ammo::Explode(int x, int y)
{
	int n = map->Width;
	int m = map->Height;

	int Radius = sing->config.weapons->Power[id] * 5;

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
				map->map[(i + j * int(n)) * 4] = 0; // R?
				map->map[(i + j * int(n)) * 4 + 1] = 0; // G?
				map->map[(i + j * int(n)) * 4 + 2] = 150; // B?
				map->map[(i + j * int(n)) * 4 + 3] = 255; // A?
			}
		}

	sing->MapUpdate = true;
}
