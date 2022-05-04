#pragma once

#include <map>
#include <vector>
#include "LayoutObject.h"

class Layout
{
public:
	std::vector<std::vector<int> > getLayoutInIntArray(); // LayoutDescription

public:
	virtual void Update(sf::RenderWindow *window) = 0;
	void Show(sf::RenderWindow *window);
		
	Layout *getNextLayout(); // sends next and make it nullptr
	bool ChangeLayout();

	void ConfirmBuffer();
	void EraseLastCharacterFromBuffer();
	void AddCharacterToBuffer(char character);

public:
	Layout();

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

protected:
	int IncId();
	void GenerateDescription(sf::RenderWindow *window);
};

// Layout for every window in game
