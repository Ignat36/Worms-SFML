#include "MainMenuLayout.h"

void MainMenuLayout::Update(sf::RenderWindow *window)
{
	int X = sf::Mouse::getPosition(*window).x;
	int Y = sf::Mouse::getPosition(*window).y;

	if (X >= 0 && X <= window->getSize().x &&
		Y >= 0 && Y <= window->getSize().y &&
		PressedMouseButton)
	{
		(*this.*Slots[ LayoutDescription[X][Y] ])();
	}
}

void MainMenuLayout::Show(sf::RenderWindow * window)
{
	background->Show(window);

	for (auto i : ObjectsList)
		i->Show(window);
}

MainMenuLayout::MainMenuLayout(sf::RenderWindow *window) : Layout(window)
{
	int w = window->getSize().x; // width
	int h = window->getSize().y; // height
	int add = h / 16;

	Objects[ObjectsMaxId] = nullptr;
	Slots[ObjectsMaxId] = &MainMenuLayout::pass;

	IncId();
	Objects[ObjectsMaxId] = new Button(ObjectsMaxId, w / 2, h / 2 + add, 0, 0, "Textures/MainMenu/NewGameButton.png", "Textures/MainMenu/CoveredNewGameButton.png");
	ObjectsList.push_back(Objects[ObjectsMaxId]);
	Slots[ObjectsMaxId] = &MainMenuLayout::new_game_button_pressed;

	IncId();
	Objects[ObjectsMaxId] = new Button(ObjectsMaxId, w / 2, h / 2 + 5 * add, 0, 0, "Textures/MainMenu/ExitGameButton.png", "Textures/MainMenu/CoveredExitGameButton.png");
	ObjectsList.push_back(Objects[ObjectsMaxId]);
	Slots[ObjectsMaxId] = &MainMenuLayout::exit_button_pressed;

	IncId();
	Objects[ObjectsMaxId] = new Button(ObjectsMaxId, w / 2, h / 2 + 3 * add, 0, 0, "Textures/MainMenu/LoadGameButton.png", "Textures/MainMenu/CoveredLoadGameButton.png");
	ObjectsList.push_back(Objects[ObjectsMaxId]);
	Slots[ObjectsMaxId] = &MainMenuLayout::load_game_button_pressed;

	background = new StaticPicture(IncId(), 0, 0, w, h, "Textures/MainMenu/Background.png");

	GenerateDescription(window);
}

void MainMenuLayout::new_game_button_pressed()
{
	LayoutChangeFlag = true;
	Next = new NewGameMenuLayout(window);
}

void MainMenuLayout::exit_button_pressed()
{
	LayoutChangeFlag = true;
}

void MainMenuLayout::load_game_button_pressed()
{
	std::cout << "load game\n";
}

void MainMenuLayout::pass() {}
