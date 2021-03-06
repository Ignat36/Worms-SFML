#pragma once

#include "WeaponConfigurations.h"
#include "Ammo.h"

class ObjectState;
class Weapon;

class PlayableObject : public DynamicObject
{
public:
	ObjectState *State;

public:
	int CurrentWeaponId;
	Weapon *CurrentWeapon;
	WeaponConfigurations *inventory;
	bool isAnimated;
	int HealthPoints;

public:
	PlayableObject(float x, float y, GameMap *map);
	void SetScreenCenter();
	void TakeDamage(int hp);
};

class ObjectState
{
public:
	virtual void ProcessInput(sf::Event event) = 0;
	virtual void Update() = 0;
	ObjectState(PlayableObject *ref);
	ObjectState *GetNext();
	int id;

protected:
	PlayableObject *reference;
	ObjectState *Next;
};

class Weapon
{
public:
	void Launch(PlayableObject *worm, float PowerPart);

	Weapon(int id);

	void Show(sf::RenderWindow *window, sf::FloatRect worm, int AttackAngle, bool direction);

private:
	Ammo *ammo;
	int WeaponId;
	sf::Texture InHandsTexture;
	sf::Sprite InHandsSprite;

private:
	void LoadSprite(std::string file);
};