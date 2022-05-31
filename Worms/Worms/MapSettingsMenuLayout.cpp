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
		if (!isButtonReleased)
			Canvas->DrawLine(PressedMouseButton, PreviousDrawPoint, sf::Vector2i(X, Y));
		else
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

	window->draw(Pen);
	window->draw(Tunels);
	window->draw(Spheres);
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
	Objects[ObjectsMaxId] = new Button(ObjectsMaxId, x, y * 14, 0, 0, "Textures/MapSettingsMenu/ExitGameButton.png", "Textures/MapSettingsMenu/CoveredExitGameButton.png");
	ObjectsList.push_back(Objects[ObjectsMaxId]);
	Slots[ObjectsMaxId] = &MapSettingsMenuLayout::exit_button_pressed;

	IncId();
	Objects[ObjectsMaxId] = new Button(ObjectsMaxId, x * 2, y * 9, 0, 0, "Textures/MapSettingsMenu/PenWidthButton.png", "Textures/MapSettingsMenu/CoveredPenWidthButton.png");
	ObjectsList.push_back(Objects[ObjectsMaxId]);
	Slots[ObjectsMaxId] = &MapSettingsMenuLayout::pen_width_pressed;

	IncId();
	Objects[ObjectsMaxId] = new Button(ObjectsMaxId, x * 2, y * 11, 0, 0, "Textures/MapSettingsMenu/TunelsCountButton.png", "Textures/MapSettingsMenu/CoveredTunelsCountButton.png");
	ObjectsList.push_back(Objects[ObjectsMaxId]);
	Slots[ObjectsMaxId] = &MapSettingsMenuLayout::tunels_count_pressed;

	IncId();
	Objects[ObjectsMaxId] = new Button(ObjectsMaxId, x * 2, y * 13, 0, 0, "Textures/MapSettingsMenu/SpheresCountButton.png", "Textures/MapSettingsMenu/CoveredSpheresCountButton.png");
	ObjectsList.push_back(Objects[ObjectsMaxId]);
	Slots[ObjectsMaxId] = &MapSettingsMenuLayout::spheres_count_pressed;

	IncId();
	Objects[ObjectsMaxId] = new Button(ObjectsMaxId, x * 5, y * 9, 0, 0, "Textures/MapSettingsMenu/ReverseMapButton.png", "Textures/MapSettingsMenu/CoveredReverseMapButton.png");
	ObjectsList.push_back(Objects[ObjectsMaxId]);
	Slots[ObjectsMaxId] = &MapSettingsMenuLayout::canvas_reverse_pressed;

	IncId();
	Objects[ObjectsMaxId] = new Button(ObjectsMaxId, x * 5, y * 11, 0, 0, "Textures/MapSettingsMenu/CreateTunelsButton.png", "Textures/MapSettingsMenu/CoveredCreateTunelsButton.png");
	ObjectsList.push_back(Objects[ObjectsMaxId]);
	Slots[ObjectsMaxId] = &MapSettingsMenuLayout::create_tunels_pressed;

	IncId();
	Objects[ObjectsMaxId] = new Button(ObjectsMaxId, x * 5, y * 13, 0, 0, "Textures/MapSettingsMenu/CreateCirclesButton.png", "Textures/MapSettingsMenu/CoveredCreateCirclesButton.png");
	ObjectsList.push_back(Objects[ObjectsMaxId]);
	Slots[ObjectsMaxId] = &MapSettingsMenuLayout::create_spheres_pressed;

	IncId();
	Objects[ObjectsMaxId] = new Button(ObjectsMaxId, x * 9, y * 11, 0, 0, "Textures/MapSettingsMenu/SaveButton.png", "Textures/MapSettingsMenu/CoveredSaveButton.png");
	ObjectsList.push_back(Objects[ObjectsMaxId]);
	Slots[ObjectsMaxId] = &MapSettingsMenuLayout::save_button_pressed;

	IncId();
	Objects[ObjectsMaxId] = new Button(ObjectsMaxId, x * 9, y * 13, 0, 0, "Textures/MapSettingsMenu/LoadButton.png", "Textures/MapSettingsMenu/CoveredLoadButton.png");
	ObjectsList.push_back(Objects[ObjectsMaxId]);
	Slots[ObjectsMaxId] = &MapSettingsMenuLayout::load_button_pressed;
	
	background = new StaticPicture(IncId(), 0, 0, w, h, "Textures/MapSettingsMenu/Background.png");
	
	Canvas = new MapCanvas(IncId(), 40, 40, w - 80, h / 2); 

	font.loadFromFile(Singleton::GetInstance()->GlobalPath + "Configurations/arial.ttf");
	Pen = sf::Text(std::to_string(Canvas->PenWidth), font);  Pen.setPosition(x * 2.75, y * 8.5); Pen.setFillColor(sf::Color::White);
	Tunels = sf::Text(std::to_string(Canvas->TunelsCount), font);  Tunels.setPosition(x * 2.75, y * 10.5); Tunels.setFillColor(sf::Color::White);
	Spheres = sf::Text(std::to_string(Canvas->SpheresCount), font);  Spheres.setPosition(x * 2.75, y * 12.5); Spheres.setFillColor(sf::Color::White);

	GenerateDescription(window);
}

void MapSettingsMenuLayout::pen_width_pressed()
{
	if (PressedMouseButton)
	{
		if (Canvas->PenWidth < 10)
		{
			Canvas->PenWidth++;
			Pen.setString(std::to_string(Canvas->PenWidth));
		}
	}
	else
	{
		if (Canvas->PenWidth > 1)
		{
			Canvas->PenWidth--;
			Pen.setString(std::to_string(Canvas->PenWidth));
		}
	}
}

void MapSettingsMenuLayout::create_tunels_pressed()
{
}

void MapSettingsMenuLayout::create_spheres_pressed()
{
}

void MapSettingsMenuLayout::spheres_count_pressed()
{
	if (PressedMouseButton)
	{
		if (Canvas->SpheresCount < 10)
		{
			Canvas->SpheresCount++;
			Spheres.setString(std::to_string(Canvas->SpheresCount));
		}
	}
	else
	{
		if (Canvas->SpheresCount > 1)
		{
			Canvas->SpheresCount--;
			Spheres.setString(std::to_string(Canvas->SpheresCount));
		}
	}
}

void MapSettingsMenuLayout::tunels_count_pressed()
{
	if (PressedMouseButton)
	{
		if (Canvas->TunelsCount < 10)
		{
			Canvas->TunelsCount++;
			Tunels.setString(std::to_string(Canvas->TunelsCount));
		}
	}
	else
	{
		if (Canvas->TunelsCount > 1)
		{
			Canvas->TunelsCount--;
			Tunels.setString(std::to_string(Canvas->TunelsCount));
		}
	}
}

void MapSettingsMenuLayout::canvas_reverse_pressed()
{
	Canvas->MapReverse();
}

void MapSettingsMenuLayout::exit_button_pressed()
{
	LayoutChangeFlag = true;
	Singleton *single = Singleton::GetInstance();
	single->config.map = Canvas->ConvertToGameMap();
}

void MapSettingsMenuLayout::load_button_pressed()
{
	std::string path = Layout::GetFileName();
	if (path == "") return;

	GameMap res = GameMap::Load(path);

	Canvas->SetMap(res.pixels);
}

void MapSettingsMenuLayout::save_button_pressed()
{
	std::string path = Layout::GetFileName();
	if (path == "") return;

	GameMap *res = Canvas->ConvertToGameMap();

	res->Save(path);
}

void MapSettingsMenuLayout::pass() {}
