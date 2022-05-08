#pragma once

#include "LayoutObject.h"
#include "GameMap.h"

class MapCanvas : public LayoutObject
{
public:
	void Show(sf::RenderWindow *window) override;
	MapCanvas(int id, float pos_x, float pos_y, float width, float height, GameMap *n_map = nullptr);

public:
	int PenWidth;
	int SpheresCount;
	int TunelsCount;

public:
	void MapReverse();
	void CreateSpheres(bool value);
	void CreateTunnels(bool value);
	void DrawPoint(bool value, sf::RenderWindow *window);

private:
	std::vector<std::vector<bool> > map;
	sf::Uint8 *pixels;
	bool NeedUpdated;
	sf::Sprite Sprite;
	sf::Texture Texture;

private:
	void UpdateTexture();
};

