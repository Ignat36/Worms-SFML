#pragma once

#include "DynamicObject.h"

class ObjectState;

class PlayableObject : public DynamicObject
{
public:
	ObjectState *State;

public:
	PlayableObject(float x, float y, GameMap *map);
	void SetScreenCenter();
};

class ObjectState
{
public:
	virtual void ProcessInput(sf::Event event) = 0;
	virtual void Update() = 0;
	ObjectState(PlayableObject *ref);
	ObjectState *GetNext();


protected:
	PlayableObject *reference;
	ObjectState *Next;
};