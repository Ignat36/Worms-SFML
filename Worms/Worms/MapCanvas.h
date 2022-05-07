#pragma once

#include "LayoutObject.h"
#include "GameMap.h"

class MapCanvas : public LayoutObject
{
public:
	void Show(sf::RenderWindow *window) override;
	MapCanvas(int id, float pos_x, float pos_y, float width, float height);

public:
	int PenWidth;
	int EraserWidth;
	bool isPen;
	int SpheresCount;
	int TunnelsCount;

public:
	void MapReverse();
	void CreateSpheres(bool value);
	void CreateTunnels(bool value);

private:
	GameMap *Map;
};

