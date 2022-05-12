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

void MapCanvas::DrawLine(bool value, sf::Vector2i start, sf::Vector2i end)
{
	NeedUpdated = true;

	int Radius = PenWidth * 5;

	std::vector<std::pair<sf::Vector2i, sf::Vector2i> > stack;

	sf::Vector2i add(start.x <= end.x ? 1 : -1, start.y <= end.y ? 1 : -1);

	stack.push_back({ start, end });
	while (!stack.empty())
	{
		sf::Vector2i l = stack.back().first;
		sf::Vector2i r = stack.back().second;
		sf::Vector2i m = (l + r) / 2;
		stack.pop_back();

		DrawPoint(value, m);

		if (l == r)
			continue;

		if(m != r) stack.push_back({ l, m });
		if(m != l) stack.push_back({ m, r });

	}
}

GameMap *MapCanvas::ConvertToGameMap()
{
	GameMap *map = new GameMap(); 
	int w = map->Width = Size.x * 5 + 2000; int h = map->Height = Size.y * 5;
	map->pixels = std::vector<std::vector<bool> >(w, std::vector<bool>(h, false));

	std::vector<std::vector<bool> > tmp(Size.x + 2, std::vector<bool>(Size.y + 2, false));

	for (int i = 1; i <= Size.x; i++)
	{
		for (int j = 1; j <= Size.y; j++)
		{
			tmp[i][j] = pixels[(i - 1 + (j - 1) * int(Size.x)) * 4] == 255;
		}
	}

	for (int i = 1; i <= Size.x; i++)
	{
		for (int j = 1; j <= Size.y; j++)
		{
			int kol = (tmp[i + 1][j] ? 1 : 0) +
				(tmp[i - 1][j] ? 1 : 0) +
				(tmp[i][j + 1] ? 1 : 0) +
				(tmp[i][j - 1] ? 1 : 0);

			int x, y;
			x = (tmp[i + 1][j] ? 1 : 0) * 5;
			y = (tmp[i][j + 1] ? 1 : 0) * 5;
			bool paral = (tmp[i + 1][j] == tmp[i - 1][j] && tmp[i + 1][j] == true) ||
				(tmp[i][j - 1] == tmp[i][j + 1] && tmp[i][j + 1] == true);
			///////////////////////////////////////////////////////////////
			for (int k = (i - 1) * 5; k < (i - 1) * 5 + 5; k++)
			{
				for (int l = (j - 1) * 5; l < (j - 1) * 5 + 5; l++)
				{
					if (tmp[i][j])
					{
						map->pixels[k + 1000][l] = true;
					}
					else
					{
						int val = abs(y - (l - (j - 1) * 5)) + abs(x - (k - (i - 1) * 5));
						if (y == x)
							val += x == 5 ? -1 : 1;
						if (kol > 1 && (kol > 2 || paral || (val <= 4)))
						{
							map->pixels[k + 1000][l] = true;
						}
						else
						{
							map->pixels[k + 1000][l] = false;
						}
					}
				}
			}
			///////////////////////////////////////////////////////
		}
	}
	return map;
}

void MapCanvas::UpdateTexture()
{
	Image.create(Size.x, Size.y, pixels);
	Texture.loadFromImage(Image);
	Sprite.setTexture(Texture);
	Sprite.setPosition(Position);
}
