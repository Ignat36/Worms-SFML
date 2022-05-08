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

	int Radius = PenWidth * 5;

	for(int i = X - Radius; i <= X + Radius; i++ )
		for (int j = Y - Radius; j <= Y + Radius; j++)
		{
			if (i < 0 || j < 0 || i > Size.x || j > Size.y || (i + j * int(Size.x)) * 4 + 3 > Size.x * Size.y * 4)
				continue;

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

void MapCanvas::DrawPoint(bool value, sf::Vector2i point)
{
	NeedUpdated = true;

	int X = point.x;
	int Y = point.y;

	int Radius = PenWidth * 5;

	for (int i = X - Radius; i <= X + Radius; i++)
		for (int j = Y - Radius; j <= Y + Radius; j++)
		{
			if (i < 0 || j < 0 || i > Size.x || j > Size.y || (i + j * int(Size.x)) * 4 + 3 > Size.x * Size.y * 4)
				continue;

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

void MapCanvas::DrawLine(bool value, sf::Vector2i start, sf::RenderWindow *window)
{
	NeedUpdated = true;

	int X = sf::Mouse::getPosition(*window).x - 40;
	int Y = sf::Mouse::getPosition(*window).y - 40;

	sf::Vector2i end(X, Y);

	int Radius = PenWidth * 5;

	int x_step = (end.x - start.x) / Radius + 1;
	int y_step = (end.y - start.y) / Radius + 1;

	for (int x = start.x, y = start.y; 
		abs(x - end.x) >= Radius && abs(y - end.y) >= Radius; 
		x += x_step, y += y_step)
	{
		DrawPoint(value, sf::Vector2i(x, y));
	}
}

void MapCanvas::UpdateTexture()
{
	Image.create(Size.x, Size.y, pixels);
	Texture.loadFromImage(Image);
	Sprite.setTexture(Texture);
	Sprite.setPosition(Position);
}
