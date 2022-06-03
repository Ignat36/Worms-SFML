#include "Weapon.h"
#include "Rocket.h"

Weapon::Weapon(int id) : WeaponId(id)
{
	switch (id)
	{
	case 0:
		LoadSprite("Textures/Weapons/Launcher.png");
		ammo = new Rocket();
		break;

	default:
		std::cout << "No such weapon id :" << id;
		exit(4);
	}
}

void Weapon::Show(sf::RenderWindow * window, sf::FloatRect worm, int AttackAngle, bool direction)
{
	if (direction)
	{
		InHandsSprite.setPosition(
			worm.left + worm.width / 2,
			worm.top + worm.height - InHandsTexture.getSize().y / 2
		);

		InHandsSprite.setOrigin(
			InHandsTexture.getSize().x / 2,
			InHandsTexture.getSize().y / 2
		);

		InHandsSprite.setScale(-1, 1);
		InHandsSprite.setRotation(-AttackAngle);
	}
	else
	{
		InHandsSprite.setPosition(
			worm.left + worm.width / 2,
			worm.top + worm.height - InHandsTexture.getSize().y / 2
		);
		InHandsSprite.setOrigin(
			InHandsTexture.getSize().x / 2,
			InHandsTexture.getSize().y / 2
		);

		InHandsSprite.setScale(1, 1);
		InHandsSprite.setRotation(AttackAngle);
	}

	window->draw(InHandsSprite);
}

void Weapon::LoadSprite(std::string file)
{
	std::string path = sing->GlobalPath + file;

	InHandsTexture = sf::Texture();
	InHandsSprite = sf::Sprite();

	if (!InHandsTexture.loadFromFile(path))
	{
		std::cout << "Can't find the image" << file << std::endl;
		sing->WindowClosed = true;
		return;
	}

	InHandsSprite.setTexture(InHandsTexture);
}
