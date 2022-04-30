#pragma once

#include "ApplicationState.h"
#include "Layout.h"

class UiState : public ApplicationState
{
private:
	Layout *CurrentLayout;
};

