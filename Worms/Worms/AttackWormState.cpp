#include "AttackWormState.h"
#include "NormalWormState.h"

void AttackWormState::ProcessInput(sf::Event event)
{
	if (event.type == sf::Event::KeyReleased)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Space:
			Attack.Stop();
			break;

		default:
			break;
		}
	}

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

		default:
			break;
		}
	}
}

void AttackWormState::Update()
{
	if (Attack.Elapsed() > MaxPowerWait || !Attack.Active())
	{
        Next = new NormalWormState(reference);

		float part = Attack.Elapsed();

		reference->CurrentWeapon->Launch(reference, part);
		Attack.Stop();

		reference->CurrentWeaponId = -1;
		reference->CurrentWeapon = nullptr;
	}
}

AttackWormState::AttackWormState(PlayableObject * ref) : ObjectState(ref)
{
	Attack.Start();
	MaxPowerWait = 1.;
}
