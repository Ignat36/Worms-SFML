#pragma once

#include "GameObject.h"

class DynamicObject : public GameObject
{
public:
	void push(float ndx, float ndy);
	virtual void Update() = 0;
	DynamicObject();
	DynamicObject(float x, float y, std::vector<std::vector<bool> > *n_map);

protected:
	float dx;
	float dy;

	float push_x;
	float push_y;

	float last_stabil_x;
	float last_stabil_y;

	int collision_x;
	int collision_y;

	std::vector<std::vector<bool> > *map;

protected:
	bool PushUp(int possible_pixels);

protected:
	void Move();
	void CalculateCollisionX(); //col_x
	void CalculateCollisionY(); //col_y
	void update_x();
	void update_y();
};

