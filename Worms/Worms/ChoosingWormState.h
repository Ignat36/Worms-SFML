#pragma once

#include "PlayableObject.h"

class ChoosingWormState : public ObjectState
{
public:
	void ProcessInput(sf::Event event) override;
	void Update() override;
	ChoosingWormState(PlayableObject *ref);
};

