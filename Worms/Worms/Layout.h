#pragma once

#include <map>
#include <vector>
#include "LayoutObject.h"

class Layout
{
public:
	int** getLayoutInIntArray(); // LayoutDescription

public:
	virtual void Update() = 0;

protected:
	int** LayoutDescription;
	std::vector<LayoutObject*> ObjectsList;
	std::map<int, LayoutObject*> Objects;
};

// Layout for every window in game
