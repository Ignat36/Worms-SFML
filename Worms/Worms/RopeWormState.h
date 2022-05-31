#pragma once

#include "PlayableObject.h"

class RopeWormState : public ObjectState
{
public:
	void ProcessInput(sf::Event event) override;
	void Update() override;
	RopeWormState(PlayableObject *ref);
};

