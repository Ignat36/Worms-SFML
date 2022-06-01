#include "PlayableObject.h"

PlayableObject::PlayableObject(float x, float y, GameMap *n_map) : DynamicObject(x, y, n_map)
{
	
}

void PlayableObject::SetScreenCenter()
{
	sing->game_mouse_position_x = window_pos_X - 640;
	sing->game_mouse_position_y = window_pos_Y - 400;
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
