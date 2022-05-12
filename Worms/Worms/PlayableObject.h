#pragma once

#include "DynamicObject.h"

class ObjectState;

class PlayableObject : public DynamicObject
{
public:
	ObjectState *State;

public:
	PlayableObject();
};

class ObjectState
{
public:
	virtual void ProcessInput(sf::RenderWindow *window) = 0;
	ObjectState(PlayableObject *ref);

protected:
	PlayableObject *reference;
};