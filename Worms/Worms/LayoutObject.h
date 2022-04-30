#pragma once

#include <string>

class LayoutObject
{
public:
	bool HidenFromUser;
	// window position / Rect 
	std::string Name;
	int ObjectId;

public:
	virtual void Interact() = 0;
};

