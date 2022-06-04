#include "Ammo.h"
#include "Singleton.h"
#include <cmath>

void Ammo::SetPosition(DynamicObject * launcher)
{
	window_pos_Y = launcher->window_pos_Y + launcher->Height / 2. +
		10 * sin((launcher->attack_angle) * 3.14 / 180.);

	window_pos_X = launcher->window_pos_X +
		launcher->direction ? launcher->Width + 7 : -7;

	direction = launcher->direction;
}

void Ammo::SetDirection(float angle)
{
	push_x = 5;
	push_y = -5;
}

void Ammo::SetStrength(float part)
{
	push_x *= part;
	push_y *= part;
}

void Ammo::Explode(int x, int y)
{
	int n = map->Width;
	int m = map->Height;

	int Radius = sing->config.weapons->Power[id];

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

	sing->MapUpdate = true;
}
