#include "Layout.h"

std::vector<std::vector<int> > Layout::getLayoutInIntArray()
{
	return LayoutDescription;
}

Layout * Layout::getNextLayout()
{
	Layout *result = Next;
	Next = nullptr;
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

Layout::Layout(sf::RenderWindow *n_window)
{
	Next = nullptr;
	LayoutChangeFlag = false;
	buffer = nullptr;
	ObjectsMaxId = 0;
	CursorType = sf::Cursor::Arrow;
	this->window = n_window;
	isButtonReleased = true;
}

int Layout::IncId()
{
	return ++ObjectsMaxId;
}

void Layout::GenerateDescription(sf::RenderWindow *window)
{
	// create LayoutDescription according to LayoutObjeccts list rects
	int n = window->getSize().x; n += 50;
	int m = window->getSize().y; m += 50;
	
	LayoutDescription.resize(n);

	for (int i = 0; i < n; i++)
	{
		LayoutDescription[i].resize(m);
		for (int j = 0; j < m; j++)
			LayoutDescription[i][j] = 0;
	}
	
	
	for (auto obj: ObjectsList)
	{
		for (int i = obj->Position.x;
			i < obj->Position.x + obj->Size.x;
			i++)

			for (int j = obj->Position.y;
				j < obj->Position.y + obj->Size.y;
				j++)

				LayoutDescription[i][j] = obj->HidenFromUser ? 0 : obj->ObjectId;
	}
}
