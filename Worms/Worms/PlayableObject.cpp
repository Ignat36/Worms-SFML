#include "PlayableObject.h"

PlayableObject::PlayableObject(float x, float y, GameMap *n_map) : DynamicObject(x, y, n_map)
{
	
}

ObjectState::ObjectState(PlayableObject * ref)
{
	reference = ref;
	Next = nullptr;
}

ObjectState *ObjectState::GetNext()
{
	ObjectState *result = Next;
	Next = nullptr;
	return result;
}