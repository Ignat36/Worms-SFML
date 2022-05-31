#pragma once

#include "PlayableObject.h"

class NoWeaponWormState : public ObjectState
{
public:
	void ProcessInput(sf::Event event) override;
	void Update() override;
	NoWeaponWormState(PlayableObject *ref);
};

