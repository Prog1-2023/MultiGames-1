#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Grid
{
	vector<RectangleShape*> tiles;
	Vector2i windowSize;
	Vector2i tilesAmount;
	Vector2f TileSize;
	
public:
	Vector2i GetTilesAmount() {
		return tilesAmount;
	}
	Vector2f GetTileSize() {
		return TileSize;
	}

public:
	Grid(const Vector2i _windowSize, const Vector2i& _tilesAmount);
	~Grid();

public:
	void Generate();
	vector<Drawable*> GetDrawables();
};