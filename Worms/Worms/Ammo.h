#pragma once

#include "DynamicObject.h"

class Ammo : public DynamicObject
{
public:
	void SetPosition(DynamicObject *launcher);
	void SetDirection(float angle);
	void SetStrength(float part);

protected:
	void Explode(int x, int y);
	int id;
};

