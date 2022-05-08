#include "NewGameMenuLayout.h"

void NewGameMenuLayout::Update(sf::RenderWindow *window)
{
	int X = sf::Mouse::getPosition(*window).x;
	int Y = sf::Mouse::getPosition(*window).y;

	if (X >= 0 && X <= window->getSize().x &&
		Y >= 0 && Y <= window->getSize().y)
	{
		(*this.*Slots[LayoutDescription[X][Y]])();
	}
}

NewGameMenuLayout::NewGameMenuLayout(sf::RenderWindow *window) : Layout(window)
{
	int w = window->getSize().x; // width
	int h = window->getSize().y; // height
	int x = w / 11;
	int y = h / 15;

	Objects[ObjectsMaxId] = nullptr;
	Slots[ObjectsMaxId] = &NewGameMenuLayout::pass;

	IncId();
	Objects[ObjectsMaxId] = new Button(ObjectsMaxId, x * 10, y * 13, 0, 0, "Textures/NewGameMenu/NewGameButton.png", "Textures/NewGameMenu/CoveredNewGameButton.png");
	ObjectsList.push_back(Objects[ObjectsMaxId]);
	Slots[ObjectsMaxId] = &NewGameMenuLayout::new_game_button_pressed;

	IncId();
	Objects[ObjectsMaxId] = new Button(ObjectsMaxId, x, y * 13, 0, 0, "Textures/NewGameMenu/ExitGameButton.png", "Textures/NewGameMenu/CoveredExitGameButton.png");
	ObjectsList.push_back(Objects[ObjectsMaxId]);
	Slots[ObjectsMaxId] = &NewGameMenuLayout::exit_button_pressed;
	
	IncId();
	Objects[ObjectsMaxId] = new Button(ObjectsMaxId, x * 2, y * 3, 0, 0, "Textures/NewGameMenu/MapSettingsButton.png", "Textures/NewGameMenu/CoveredMapSettingsButton.png");
	ObjectsList.push_back(Objects[ObjectsMaxId]);
	Slots[ObjectsMaxId] = &NewGameMenuLayout::map_settings_button_pressed;
	
	IncId();
	Objects[ObjectsMaxId] = new Button(ObjectsMaxId, x * 2, y * 5, 0, 0, "Textures/NewGameMenu/GameSettingsButton.png", "Textures/NewGameMenu/CoveredGameSettingsButton.png");
	ObjectsList.push_back(Objects[ObjectsMaxId]);
	Slots[ObjectsMaxId] = &NewGameMenuLayout::game_settings_button_pressed;
	
	IncId();
	Objects[ObjectsMaxId] = new Button(ObjectsMaxId, x * 5, y * 3, 0, 0, "Textures/NewGameMenu/SaveButton.png", "Textures/NewGameMenu/CoveredSaveButton.png");
	ObjectsList.push_back(Objects[ObjectsMaxId]);
	Slots[ObjectsMaxId] = &NewGameMenuLayout::save_button_pressed;
	
	IncId();
	Objects[ObjectsMaxId] = new Button(ObjectsMaxId, x * 5, y * 5, 0, 0, "Textures/NewGameMenu/LoadButton.png", "Textures/NewGameMenu/CoveredLoadButton.png");
	ObjectsList.push_back(Objects[ObjectsMaxId]);
	Slots[ObjectsMaxId] = &NewGameMenuLayout::load_button_pressed;
	
	IncId();
	Objects[ObjectsMaxId] = new Button(ObjectsMaxId, x * 8, y * 3, 0, 0, "Textures/NewGameMenu/WeaponSettingsButton.png", "Textures/NewGameMenu/CoveredWeaponSettingsButton.png");
	ObjectsList.push_back(Objects[ObjectsMaxId]);
	Slots[ObjectsMaxId] = &NewGameMenuLayout::weapon_settings_button_pressed;
	
	IncId();
	Objects[ObjectsMaxId] = new Button(ObjectsMaxId, x * 8, y * 5, 0, 0, "Textures/NewGameMenu/TeamsSettingsButton.png", "Textures/NewGameMenu/CoveredTeamsSettingsButton.png");
	ObjectsList.push_back(Objects[ObjectsMaxId]);
	Slots[ObjectsMaxId] = &NewGameMenuLayout::teams_settings_button_pressed;

	background = new StaticPicture(IncId(), 0, 0, w, h, "Textures/NewGameMenu/Background.png");

	GenerateDescription(window);
}

void NewGameMenuLayout::new_game_button_pressed()
{
	std::cout << "new game\n";
}

void NewGameMenuLayout::exit_button_pressed()
{
	LayoutChangeFlag = true;
}

void NewGameMenuLayout::load_button_pressed()
{
}

void NewGameMenuLayout::save_button_pressed()
{
}

void NewGameMenuLayout::game_settings_button_pressed()
{
	//Next = new GameSettingsMenuLayout();
}

void NewGameMenuLayout::map_settings_button_pressed()
{
	LayoutChangeFlag = true;
	Next = new MapSettingsMenuLayout(window);
}

void NewGameMenuLayout::teams_settings_button_pressed()
{
}

void NewGameMenuLayout::weapon_settings_button_pressed()
{
}

void NewGameMenuLayout::pass() {}
