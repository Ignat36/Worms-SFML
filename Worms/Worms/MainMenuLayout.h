#pragma once

#include "Layout.h"
#include "Button.h"
#include "StaticPicture.h"

class MainMenuLayout : public Layout
{
public:
	void Update(sf::RenderWindow *window) override;
	MainMenuLayout();

private:
	Button *new_game_button;
	Button *exit_button;
	Button *load_game_button;

private:
	void new_game_button_pressed();
	void exit_button_pressed();
	void load_game_button_pressed();
	void pass();
	std::map<int, void (MainMenuLayout::*)()> Slots;

private:
	void TemporaryFunction() {};
};


