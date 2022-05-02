#include "Layout.h"

int ** Layout::getLayoutInIntArray()
{
	return LayoutDescription;
}

void Layout::Show(sf::RenderWindow *window)
{
	background->Show(window);

	for (auto i : ObjectsList)
		i->Show(window);

	sf::Cursor cursor;
	if (cursor.loadFromSystem(CursorType))
		window->setMouseCursor(cursor);
}

Layout * Layout::getNextLayout()
{
	Layout *result = next;
	next = nullptr;
	return result;
}

bool Layout::ChangeLayout()
{
	bool result = LayoutChangeFlag;
	LayoutChangeFlag = false;
	return result;
}

void Layout::ConfirmBuffer()
{
	buffer = nullptr;
}

void Layout::EraseLastCharacterFromBuffer()
{
	buffer->pop_back();
}

void Layout::AddCharacterToBuffer(char character)
{
	if (buffer == nullptr)
		return;

	if (character >= 'a' && character <= 'z')
		character = character - 'a' + 'A';
	
	if (character >= 'A' && character <= 'Z')
		*buffer += character;
}

Layout::Layout()
{
	next = nullptr;
	LayoutChangeFlag = false;
	buffer = nullptr;
	ObjectsMaxId = 0;
	CursorType = sf::Cursor::Arrow;
}

int Layout::IncId()
{
	return ++ObjectsMaxId;
}

void Layout::GenerateDescription()
{
	// create LayoutDescription according to LayoutObjeccts list rects
}
