#include "Singleton.h"

Singleton* Singleton::singleton_ = nullptr;;

Singleton *Singleton::GetInstance()
{
	if (singleton_ == nullptr) {
		singleton_ = new Singleton();
	}
	return singleton_;
}

void Singleton::ShowMap(GameMap * m, sf::RenderWindow * window)
{
	Singleton *single = Singleton::GetInstance();

	int x = single->game_mouse_position_x;
	int y = single->game_mouse_position_y;

	m->CurrentMapSprite.setPosition(-x, -y);
	window->draw(m->CurrentMapSprite);
}
