#pragma once

#include "Layout.h"
#include "MapCanvas.h"
#include "Button.h"

class MapSettingsMenuLayout : public Layout
{
public:
	void Update(sf::RenderWindow *window) override;
	MapSettingsMenuLayout(sf::RenderWindow *window);

private:
	Button *new_game_button;
	Button *exit_button;
	Button *load_game_button;
	MapCanvas Canvas;

private:
	void new_game_button_pressed();
	void exit_button_pressed();
	void load_game_button_pressed();
	void pass();
	std::map<int, void (MapSettingsMenuLayout::*)()> Slots;
};

