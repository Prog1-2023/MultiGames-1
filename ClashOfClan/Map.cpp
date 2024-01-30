#include "Map.h"

Map::Map(const int _id) : IManagable(_id)
{
	tiles = vector<RectangleShape*>();
	tilesCount = Vector2i();
	tileSize = Vector2f();
}
