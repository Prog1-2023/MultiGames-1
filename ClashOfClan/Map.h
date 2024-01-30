#pragma once
#include "IManagable.h"
#include "Building.h"

class Map : public IManagable<int>
{
	vector<RectangleShape*> tiles;
	Vector2i tilesCount;
	Vector2f tileSize;

public:
	Map(const int _id);
};

