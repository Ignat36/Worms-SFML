#include "MapCanvas.h"

void MapCanvas::Show(sf::RenderWindow * window)
{
	if (NeedUpdated)
	{
		NeedUpdated = false;
		UpdateTexture();
	}

	window->draw(Sprite);
}

MapCanvas::MapCanvas(int id, float pos_x, float pos_y, float width, float height, GameMap *n_map) : LayoutObject(id, pos_x, pos_y, width, height)
{
	NeedUpdated = true;
	PenWidth = 1;
	SpheresCount = 5;
	TunelsCount = 5;

	map.resize(height + 20);
	for (int i = 0; i < map.size(); i++)
		map[i].resize(width + 20);

	pixels = new sf::Uint8[width * height * 4];

	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			pixels[ (x + y * int(width)) * 4] = 0; // R?
			pixels[ (x + y * int(width)) * 4 + 1] = 0; // G?
			pixels[ (x + y * int(width)) * 4 + 2] = 255; // B?
			pixels[ (x + y * int(width)) * 4 + 3] = 255; // A?
		}
	}
}

void MapCanvas::MapReverse()
{
	NeedUpdated = true;

	for (int x = 0; x < Size.x; x++)
	{
		for (int y = 0; y < Size.y; y++)
		{
			for (int k = 0; k < 3; k++)
			{
				pixels[(x + y * int(Size.x)) * 4 + k] = abs(pixels[(x + y * int(Size.x)) * 4 + k] - 255);
			}
		}
	}
}

void MapCanvas::CreateSpheres(bool value)
{
}

void MapCanvas::CreateTunnels(bool value)
{
}

void MapCanvas::DrawPoint(bool value, sf::RenderWindow *window)
{
	NeedUpdated = true;

	int X = sf::Mouse::getPosition(*window).x - 40;
	int Y = sf::Mouse::getPosition(*window).y - 40;

	int Radius = PenWidth * 15;

	for(int i = X - Radius; i <= X + Radius; i++ )
		for (int j = Y - Radius; j <= Y + Radius; j++)
		{
			int tx = X - i;
			int ty = Y - j;

			if (tx*tx + ty * ty < Radius * Radius)
			{
				pixels[(i + j * int(Size.x)) * 4] = value ? 255 : 0; // R?
				pixels[(i + j * int(Size.x)) * 4 + 1] = value ? 255 : 0; // G?
				pixels[(i + j * int(Size.x)) * 4 + 2] = value ? 0 : 255; // B?
				pixels[(i + j * int(Size.x)) * 4 + 3] = 255; // A?
			}
		}
}

void MapCanvas::UpdateTexture()
{
	sf::Image img; img.create(Size.x, Size.y, pixels);
	Texture.update(img);
	Sprite.setTexture(Texture);
	Sprite.setPosition(Position);
}
