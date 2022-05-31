#include "GameMap.h"

GameMap::GameMap()
{
	/*Height = 2000;
	Width = 6000;
	pixels.resize(Height);
	std::string path = "Maps/Standart/map" + std::to_string(rand() % 1) + ".txt";
	std::ifstream fin(path); fin.open("r");
	std::string str;
	int i = 0;
	while (fin >> str)
	{
		pixels[i++].resize(Width);
		for (int j = 0; j < str.size(); j++)
			pixels[i][j] = str[j] == '1';
	}*/
}

void GameMap::Expand()
{
	int w = Width * 5 + 2000; int h = Height * 5;
	
	map = new sf::Uint8[w * h * 4];

	std::vector<std::vector<bool> > tmp(Width + 2, std::vector<bool>(Height + 2, false));

	for (int i = 1; i <= Width; i++)
	{
		for (int j = 1; j <= Height; j++)
		{
			tmp[i][j] = pixels[i-1][j-1];
		}
	}

	pixels = std::vector<std::vector<bool> >(w, std::vector<bool>(h));


	for (int i = 1; i <= Width; i++)
	{
		for (int j = 1; j <= Height; j++)
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
						pixels[k + 1000][l] = true;
					}
					else
					{
						int val = abs(y - (l - (j - 1) * 5)) + abs(x - (k - (i - 1) * 5));
						if (y == x)
							val += x == 5 ? -1 : 1;
						if (kol > 1 && (kol > 2 || paral || (val <= 4)))
						{
							pixels[k + 1000][l] = true;
						}
						else
						{
							pixels[k + 1000][l] = false;
						}
					}
				}
			}
			///////////////////////////////////////////////////////
		}
	}

	Width = w; 
	Height = h;
}

void GameMap::UpdateSprite()
{
	CurrentMapImage.create(pixels.size(), pixels[0].size(), map);
	CurrentMapTexture.loadFromImage(CurrentMapImage);
	CurrentMapSprite.setTexture(CurrentMapTexture);
	CurrentMapSprite.setPosition(0, 0);
}

void GameMap::FullReRender()
{
	for (int i = 0; i < Width; i++)
		for (int j = 0; j < Height; j++)
			if (pixels[i][j])
			{
				map[(i + j * Width) * 4] = DefaultMap[(i + j * Width) * 4];
				map[(i + j * Width) * 4 + 1] = DefaultMap[(i + j * Width) * 4 + 1];
				map[(i + j * Width) * 4 + 2] = DefaultMap[(i + j * Width) * 4 + 2];
				map[(i + j * Width) * 4 + 3] = DefaultMap[(i + j * Width) * 4 + 3];
			}
			else
			{
				map[(i + j * Width) * 4] = 0;
				map[(i + j * Width) * 4 + 1] = 0;
				map[(i + j * Width) * 4 + 2] = 150;
				map[(i + j * Width) * 4 + 3] = 255;
			}
}

void GameMap::Save(std::string file)
{
	std::string path = file;
	std::ofstream fout; fout.open(path);
	
	int kol = 0;

	for (int i = 0; i < Width; i++)
	{
		for (int j = 0; j < Height; j++)
		{
			fout << pixels[i][j];
			kol += pixels[i][j];
		}
		fout << "\n";
	}

	fout.close();
}

GameMap GameMap::Load(std::string file)
{
	GameMap result = GameMap();
	std::string path = file;
	std::ifstream fin; fin.open(path);
	std::string str;
	int i = 0;
	while (fin >> str)
	{
		std::vector<bool> col;
		col.resize(str.size());
		for (int j = 0; j < str.size(); j++)
			col[j] = str[j] == '1';

		result.pixels.push_back(col);
	}

	return result;
}

