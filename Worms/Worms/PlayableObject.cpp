#include "PlayableObject.h"

PlayableObject::PlayableObject() : DynamicObject()
{
}

ObjectState::ObjectState(PlayableObject * ref)
{
	reference = ref;
}