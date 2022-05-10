#pragma once

#include "DynamicObject.h"
#include "ObjectState.h"

class PlayableObject : public DynamicObject
{
public:
	ObjectState *State;

public:
	PlayableObject();
};

