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
			reference->dy = -6;
			reference->push_x = 3 * (reference->direction ? 1 : -1);
			sing->isAnimation = true;
			break;


		case sf::Keyboard::BackSpace:
			reference->dy = -8;
			reference->push_x = 2 * (reference->direction ? -1 : 1);
			sing->isAnimation = true;
			break;

		default:
			break;
		}
	}

	if (event.type == sf::Event::MouseWheelScrolled)
	{
		if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
			std::cout << "wheel type: vertical" << std::endl;
		else if (event.mouseWheelScroll.wheel == sf::Mouse::HorizontalWheel)
			std::cout << "wheel type: horizontal" << std::endl;
		else
			std::cout << "wheel type: unknown" << std::endl;
		std::cout << "wheel movement: " << event.mouseWheelScroll.delta << std::endl;
		std::cout << "mouse x: " << event.mouseWheelScroll.x << std::endl;
		std::cout << "mouse y: " << event.mouseWheelScroll.y << std::endl;
	}

	if (sing->isAnimation == true)
		Next = new WaitWormState(reference);
}

void NormalWormState::Update()
{
}

NormalWormState::NormalWormState(PlayableObject * ref) : ObjectState(ref)
{
}
