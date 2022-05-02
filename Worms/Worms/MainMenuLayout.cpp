#include "MainMenuLayout.h"

void MainMenuLayout::Update(sf::RenderWindow *window)
{
	int X = sf::Mouse::getPosition(*window).x;
	int Y = sf::Mouse::getPosition(*window).y;

	if (X >= 0 && X <= window->getSize().x &&
		Y >= 0 && Y <= window->getSize().y)
	{
		(*this.*Slots[ LayoutDescription[X][Y] ])();
	}
}

MainMenuLayout::MainMenuLayout()
{
	Objects[ObjectsMaxId] = nullptr;
	Slots[ObjectsMaxId] = &MainMenuLayout::pass;

	IncId();
	Objects[ObjectsMaxId] = new Button(ObjectsMaxId);
	ObjectsList.push_back(Objects[ObjectsMaxId]);
	Slots[ObjectsMaxId] = &MainMenuLayout::new_game_button_pressed;

	IncId();
	Objects[ObjectsMaxId] = new Button(ObjectsMaxId);
	ObjectsList.push_back(Objects[ObjectsMaxId]);
	Slots[ObjectsMaxId] = &MainMenuLayout::exit_button_pressed;

	IncId();
	Objects[ObjectsMaxId] = new Button(ObjectsMaxId);
	ObjectsList.push_back(Objects[ObjectsMaxId]);
	Slots[ObjectsMaxId] = &MainMenuLayout::load_game_button_pressed;

	background = new StaticPicture(IncId());
}

void MainMenuLayout::pass() {}
