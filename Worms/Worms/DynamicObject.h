#pragma once

#include "GameObject.h"

class DynamicObject : public GameObject
{
public:
	void push(float ndx, float ndy);
	virtual void Update() = 0;
	DynamicObject();
	DynamicObject(float x, float y, GameMap *map);

public:
	float dx;
	float dy;

	float push_x;
	float push_y;

	float attack_angle;

	bool direction;
	
	int NoActionFrames;

protected:
	float last_stabil_x;
	float last_stabil_y;

	int collision_x;
	int collision_y;
	int collisionVariable;

	GameMap *map;

protected:
	bool Push(int possible_pixels);

protected:
	void Move(int pixelsPush);
	void CalculateCollisionX(); //col_x
	void CalculateCollisionY(); //col_y
	void CalculateCollision(); //col_y
	bool isStable();
	void update_x();
	void update_y();
};

