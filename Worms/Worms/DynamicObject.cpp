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
}

DynamicObject::DynamicObject(float x, float y, std::vector<std::vector<bool> > *n_map) : GameObject(x, y)
{
	dx = 0;
	dy = 0;
	push_x = 0;
	map = n_map;
}

bool DynamicObject::PushUp(int possible_pixels)
{
	return false;
}

void DynamicObject::Move()
{
	window_pos_X += collision_x * dx;
	window_pos_Y += collision_y * dy;
}

void DynamicObject::CalculateCollisionX()
{
}

void DynamicObject::CalculateCollisionY()
{
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
