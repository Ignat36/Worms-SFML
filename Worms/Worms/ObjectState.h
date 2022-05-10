#pragma once

#include "PlayableObject.h"

class ObjectState
{
public:
	virtual void ProcessInput(sf::RenderWindow *window) = 0;
	ObjectState(PlayableObject *ref);

protected:
	PlayableObject *reference;
};

