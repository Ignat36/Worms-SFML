#include "PlayableObject.h"

PlayableObject::PlayableObject(float x, float y, std::vector<std::vector<bool> > *n_map) : DynamicObject(x, y, n_map)
{
	////////////////////////
	//////////////////////
	////////////////////////
	/////////////////////////
	///////////////////////////
	////////////////////////
}

ObjectState::ObjectState(PlayableObject * ref)
{
	reference = ref;
}