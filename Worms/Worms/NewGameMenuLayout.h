#pragma once

#include "Layout.h"
#include "Button.h"
#include "StaticPicture.h"
#include "GameSettingsMenuLayout.h"
#include "MapSettingsMenuLayout.h"
#include "WeaponSettingsMenuLayout.h"
#include "TeamsSettingsMenuLayout.h"

class NewGameMenuLayout : public Layout
{
public:
	void Update(sf::RenderWindow *window) override;
	void Show(sf::RenderWindow *window) override;
	NewGameMenuLayout(sf::RenderWindow *window);

private:
	Button *new_game_button;
	Button *exit_button;
	Button *load_button;
	Button *save_button;
	Button *game_settings_button;
	Button *map_settings_button;
	Button *teams_settings_button;
	Button *weapon_settings_button;

private:
	void new_game_button_pressed();
	void exit_button_pressed();
	void load_button_pressed();
	void save_button_pressed();
	void game_settings_button_pressed();
	void map_settings_button_pressed();
	void teams_settings_button_pressed();
	void weapon_settings_button_pressed();
	void pass();
	std::map<int, void (NewGameMenuLayout::*)()> Slots;
};

