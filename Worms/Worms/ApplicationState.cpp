#include "ApplicationState.h"

ApplicationState::ApplicationState()
{
	Next = nullptr;
	StateChangeFlag = false;
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
