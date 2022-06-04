#include "GameObject.h"
#include "Singleton.h"

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
	sf::Texture *tmp = new sf::Texture();
	if (!tmp->loadFromFile(file))
	{
		std::cout << "Can't find the image" << file << std::endl;
		Singleton *single = Singleton::GetInstance();
		single->WindowClosed = true;
		return false;
	}
	textures.push_back(tmp);
	sprites.push_back(new sf::Sprite(*tmp));
	return true;
}

void GameObject::LoadSprite(std::string file)
{
	Singleton *single = Singleton::GetInstance();
	std::string path = single->GlobalPath + file;

	textures.push_back(new sf::Texture());
	sprites.push_back(new sf::Sprite());

	if (!textures.back()->loadFromFile(path))
	{
		std::cout << "Can't find the image" << file << std::endl;
		Singleton *single = Singleton::GetInstance();
		single->WindowClosed = true;
		return;
	}

	sprites.back()->setTexture(*(textures.back()));
}
