#include "DynamicObject.h"

void DynamicObject::push(float ndx, float ndy)
{
	push_x = ndx;
	push_y = ndy;
}

DynamicObject::DynamicObject() : GameObject()
{
	dx = 0;
	dy = 0;
	push_x = 0;
	push_y = 0;

	attack_angle = 0;
}

DynamicObject::DynamicObject(float x, float y, GameMap *n_map) : GameObject(x, y)
{
	dx = 0;
	dy = 0;
	push_x = 0;
	push_y = 0;
	map = n_map;

	attack_angle = 0;
}

bool DynamicObject::PushUp(int possible_pixels)
{
	return true;
}

void DynamicObject::Move()
{
	window_pos_X += collision_x * dx;
	window_pos_Y += collision_y * dy;

	if (!PushUp(3))
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
	collision_y = 1;
}

bool DynamicObject::isStable()
{
	return false;
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
