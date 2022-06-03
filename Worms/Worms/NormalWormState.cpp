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
			if (reference->attack_angle < 90) 
				reference->attack_angle += 5;
			break;

		case sf::Keyboard::Down:
			if (reference->attack_angle > -90)
				reference->attack_angle -= 5;
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
		int add = event.mouseWheelScroll.delta;

		std::vector<int> &uses = reference->inventory->Uses;

		int i = reference->CurrentWeaponId;

		if (i == -1)
		{
			i = 0;
			for(; i < reference->inventory->Count; i++)
				if (uses[i])
				{
					reference->CurrentWeaponId = i;
					reference->CurrentWeapon = new Weapon(i);
					break;
				}

			if (i == reference->inventory->Count)
				i = -1;
		}
		else
		{
			i += add;

			while (true)
			{
				if (i == reference->inventory->Count)
					i = 0;

				if (i == -1)
					i = reference->inventory->Count - 1;

				if (i == reference->CurrentWeaponId)
				{
					reference->CurrentWeaponId = -1;
					reference->CurrentWeapon = nullptr;
					break;
				}

				if (uses[i])
				{
					reference->CurrentWeaponId = i;
					reference->CurrentWeapon = new Weapon(i);
					break;
				}

				i += add;
			}
		}
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
