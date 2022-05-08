#include "MapSettingsMenuLayout.h"

void MapSettingsMenuLayout::Update(sf::RenderWindow *window)
{
	int X = sf::Mouse::getPosition(*window).x;
	int Y = sf::Mouse::getPosition(*window).y;

	if (X >= 0 && X <= window->getSize().x &&
		Y >= 0 && Y <= window->getSize().y)
	{
		(*this.*Slots[LayoutDescription[X][Y]])();
	}

	X -= 40; Y -= 40;

	sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
	sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

	if (Canvas->Rect.contains(mousePosF))
	{
		/*if (!isButtonReleased)
			Canvas->DrawLine(PressedMouseButton, PreviousDrawPoint, window);
		else*/
			Canvas->DrawPoint(PressedMouseButton, sf::Vector2i(X, Y));

		PreviousDrawPoint = sf::Vector2i(X, Y);
	}
}

void MapSettingsMenuLayout::Show(sf::RenderWindow * window)
{
	background->Show(window);

	for (auto i : ObjectsList)
		i->Show(window);

	Canvas->Show(window);
}

MapSettingsMenuLayout::MapSettingsMenuLayout(sf::RenderWindow *window) : Layout(window)
{
	int w = window->getSize().x; // width
	int h = window->getSize().y; // height
	int x = w / 11;
	int y = h / 15;

	Objects[ObjectsMaxId] = nullptr;
	Slots[ObjectsMaxId] = &MapSettingsMenuLayout::pass;

	IncId();
	Objects[ObjectsMaxId] = new Button(ObjectsMaxId, x, y * 13, 0, 0, "Textures/MapSettingsMenu/ExitGameButton.png", "Textures/MapSettingsMenu/CoveredExitGameButton.png");
	ObjectsList.push_back(Objects[ObjectsMaxId]);
	Slots[ObjectsMaxId] = &MapSettingsMenuLayout::exit_button_pressed;
	
	background = new StaticPicture(IncId(), 0, 0, w, h, "Textures/MapSettingsMenu/Background.png");
	
	Canvas = new MapCanvas(IncId(), 40, 40, w - 80, h / 2);
	GenerateDescription(window);
}

void MapSettingsMenuLayout::pen_width_pressed()
{
}

void MapSettingsMenuLayout::create_tunels_pressed()
{
}

void MapSettingsMenuLayout::create_spheres_pressed()
{
}

void MapSettingsMenuLayout::spheres_count_pressed()
{
}

void MapSettingsMenuLayout::tunels_count_pressed()
{
}

void MapSettingsMenuLayout::canvas_reverse_pressed()
{
}

void MapSettingsMenuLayout::exit_button_pressed()
{
	LayoutChangeFlag = true;
}

void MapSettingsMenuLayout::load_button_pressed()
{
}

void MapSettingsMenuLayout::save_button_pressed()
{
}

void MapSettingsMenuLayout::pass() {}
