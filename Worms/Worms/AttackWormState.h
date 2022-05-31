#pragma once

#include "PlayableObject.h"
class AttackWormState : public ObjectState
{
public:
	void ProcessInput(sf::Event event) override;
	void Update() override;
	AttackWormState(PlayableObject *ref);
};

