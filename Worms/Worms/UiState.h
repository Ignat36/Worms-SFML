#pragma once

#include "ApplicationState.h"
#include "Layout.h"
#include "MainMenuLayout.h"
#include "Singleton.h"
#include "GameState.h"

class UiState : public ApplicationState
{
public:
	UiState(sf::RenderWindow *window, long long *_lag);

public:
	void ProcessInput(sf::RenderWindow *window) override;
	void UpdateObjects() override;
	void RenderObjects(sf::RenderWindow *window) override;

private:
	std::vector<Layout *> CurrentLayout;

	long long *lag;
	bool isButtonPressed;
};
