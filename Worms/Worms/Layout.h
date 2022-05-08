#pragma once

#include <map>
#include <vector>
#include <string.h>
#include <iostream>

#include "LayoutObject.h"

class Layout
{
public:
	std::vector<std::vector<int> > getLayoutInIntArray(); // LayoutDescription

public:
	virtual void Update(sf::RenderWindow *window) = 0;
	virtual void Show(sf::RenderWindow *window) = 0;
		
	Layout *getNextLayout(); // sends next and make it nullptr
	bool ChangeLayout();

	void ConfirmBuffer();
	void EraseLastCharacterFromBuffer();
	void AddCharacterToBuffer(char character);

	bool PressedMouseButton;
	bool isButtonReleased;

public:
	Layout(sf::RenderWindow *n_window);

public:

protected:
	std::vector<std::vector<int> > LayoutDescription;
	std::vector<LayoutObject*> ObjectsList;
	std::map<int, LayoutObject*> Objects;
	LayoutObject *background;
	sf::Cursor::Type CursorType;

	std::string *buffer;

	Layout *Next;
	bool LayoutChangeFlag;

	int ObjectsMaxId;

	sf::RenderWindow *window;

protected:
	int IncId();
	void GenerateDescription(sf::RenderWindow *window);
};

// Layout for every window in game
