#pragma once

#include <map>
#include <vector>
#include "LayoutObject.h"
#include "TextLayoutObject.h"

class Layout
{
public:
	int** getLayoutInIntArray(); // LayoutDescription

public:
	virtual void Update() = 0;
		
	Layout *getNextLayout(); // sends next and make it nullptr

	void ConfirmBuffer();
	void EraseLastCharacterFromBuffer();

public:
	Layout();

protected:
	int** LayoutDescription;
	std::vector<LayoutObject*> ObjectsList;
	std::map<int, LayoutObject*> Objects;

	std::string buffer;
	TextLayoutObject *CurrentEditObject;

	Layout *next;
};

// Layout for every window in game
