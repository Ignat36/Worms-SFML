#pragma once

#include "PlayableObject.h"
#include "NormalWormState.h"

class WaitWormState : public ObjectState
{
public:
	void ProcessInput(sf::Event event) override;
	void Update() override;
	WaitWormState(PlayableObject *ref);
};

