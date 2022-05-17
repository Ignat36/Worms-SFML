#pragma once

#include "DynamicObject.h"

class ObjectState;

class PlayableObject : public DynamicObject
{
public:
	ObjectState *State;

public:
	PlayableObject(float x, float y, std::vector<std::vector<bool> > *n_map);
};

class ObjectState
{
public:
	virtual void ProcessInput(sf::Event event) = 0;
	ObjectState(PlayableObject *ref);

protected:
	PlayableObject *reference;
};