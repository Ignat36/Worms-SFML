#include "LayoutObject.h"

LayoutObject::LayoutObject(int id, float pos_x, float pos_y, float width, float height)
{
	HidenFromUser = false;
	Name = Text = "";
	ObjectId = id;
	Position = sf::Vector2f(pos_x, pos_y);
	Size = sf::Vector2f(width, height);
	Rect = sf::FloatRect(Position, Size);
}

void LayoutObject::LoadSprite(sf::Texture &texture, sf::Sprite &sprite, std::string &file)
{
	Singleton *single = Singleton::GetInstance();
	std::string path = single->GlobalPath + file;

	sf::Texture exitButton;
	sf::Sprite exitButtonImage;
	if (!texture.loadFromFile(path))
	{
		std::cout << "Can't find the image" << file << std::endl;
		Singleton *single = Singleton::GetInstance();
		single->WindowClosed = true;
		return;
	}
	sprite.setTexture(texture);
	sprite.setPosition(Position);
}
