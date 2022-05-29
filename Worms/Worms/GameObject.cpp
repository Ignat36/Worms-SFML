#include "GameObject.h"

GameObject::GameObject()
{
	window_pos_X = 0;
	window_pos_Y = 0;
	isAlive = true;
}

GameObject::GameObject(float x, float y)
{
	window_pos_X = x;
	window_pos_Y = y;
	isAlive = true;
}

bool GameObject::isDead()
{
	return !isAlive;
}

bool GameObject::AddTexture(std::string file)
{
	sf::Texture tmp;
	if (!tmp.loadFromFile(file))
	{
		std::cout << "Can't find the image" << file << std::endl;
		Singleton *single = Singleton::GetInstance();
		single->WindowClosed = true;
		return false;
	}
	textures.push_back(tmp);
	sprites.push_back(sf::Sprite(tmp));
	return true;
}

void GameObject::LoadSprite(std::string file)
{
	sf::Texture texture;
	sf::Sprite sprite;
	if (!texture.loadFromFile(file))
	{
		std::cout << "Can't find the image" << file << std::endl;
		Singleton *single = Singleton::GetInstance();
		single->WindowClosed = true;
		return;
	}
	sprite.setTexture(texture);

	textures.push_back(texture);
	sprites.push_back(sprite);
}
