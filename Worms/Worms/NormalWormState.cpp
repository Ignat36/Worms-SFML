#include "NormalWormState.h"
#include "WaitWormState.h"
#include "Singleton.h"

void NormalWormState::ProcessInput(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Up:
			reference->attack_angle += 1;
			break;

		case sf::Keyboard::Down:
			reference->attack_angle -= 1;
			break;

		case sf::Keyboard::Left:
			reference->dx = -2;
			break;

		case sf::Keyboard::Right:
			reference->dx = 2;
			break;

		case sf::Keyboard::Enter:
			reference->dy = -10;
			sing->isAnimation = true;
			Next = new WaitWormState(reference);
			break;

		default:
			break;
		}
	}
}

void NormalWormState::Update()
{
}

NormalWormState::NormalWormState(PlayableObject * ref) : ObjectState(ref)
{
}
