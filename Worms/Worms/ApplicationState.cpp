#include "ApplicationState.h"

ApplicationState::ApplicationState(sf::RenderWindow *window)
{
	Next = nullptr;
	StateChangeFlag = false;
	this->window = window;
}

ApplicationState * ApplicationState::getNextState()
{
	ApplicationState *result = Next;
	Next = nullptr;
	return result;
}

bool ApplicationState::ChangeState()
{
	bool result = StateChangeFlag;
	StateChangeFlag = false;
	return result;
}
