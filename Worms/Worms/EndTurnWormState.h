#pragma once

#include "PlayableObject.h"

class EndTurnWormState : public ObjectState
{
public:
	void ProcessInput(sf::Event event) override;
	void Update() override;
	EndTurnWormState(PlayableObject *ref);
};

