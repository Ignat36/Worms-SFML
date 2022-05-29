#pragma once

#include "PlayableObject.h"

class NormalWormState : public ObjectState
{
public:
	void ProcessInput(sf::Event event) override;
	void Update() override;
	NormalWormState(PlayableObject *ref);
};

