#include "WaitWormState.h"
#include "Singleton.h"

void WaitWormState::ProcessInput(sf::Event event)
{
	
}

void WaitWormState::Update()
{
	Singleton *single = Singleton::GetInstance();
	if (reference->isAnimated == false)
	{
		Next = new NormalWormState(reference);
	}
}

WaitWormState::WaitWormState(PlayableObject * ref) : ObjectState(ref)
{
}
