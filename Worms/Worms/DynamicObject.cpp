#include "DynamicObject.h"

void DynamicObject::setMove(float ndx, float ndy)
{
	dx = ndx;
	dy = ndy;
}

DynamicObject::DynamicObject() : GameObject()
{
	dx = 0;
	dy = 0;
	push_x = 0;
}

DynamicObject::DynamicObject(float x, float y, std::vector<std::vector<bool> > *n_map) : GameObject(x, y)
{
	dx = 0;
	dy = 0;
	push_x = 0;
	map = n_map;
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
