#pragma once

#include "Layout.h"
#include "MapCanvas.h"
#include "StaticPicture.h"
#include "Button.h"

class MapSettingsMenuLayout : public Layout
{
public:
	void Update(sf::RenderWindow *window) override;
	MapSettingsMenuLayout(sf::RenderWindow *window);

private:
	Button *exit_button;
	Button *load_button;
	Button *save_button;
	Button *pen_width;
	Button *create_tunels;
	Button *create_spheres;
	Button *spheres_count;
	Button *tunels_count;
	Button *canvas_reverse;

	MapCanvas *Canvas;

private:
	void pen_width_pressed();
	void create_tunels_pressed();
	void create_spheres_pressed();
	void spheres_count_pressed();
	void tunels_count_pressed();
	void canvas_reverse_pressed();
	void exit_button_pressed();
	void load_button_pressed();
	void save_button_pressed();
	void pass();
	std::map<int, void (MapSettingsMenuLayout::*)()> Slots;
};

