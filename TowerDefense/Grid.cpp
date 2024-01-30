#include "Grid.h"

Grid::Grid(const Vector2i _windowSize, const Vector2i& _tilesAmount)
{
	windowSize = _windowSize;
	tilesAmount = _tilesAmount;
	windowSize = Vector2i();
	tiles = vector<RectangleShape*>();
	TileSize = Vector2f();
}

Grid::~Grid()
{
	for (RectangleShape* _shape : tiles)
	{
		delete _shape;
	}
}

void Grid::Generate()
{
	const float _tileWidth = static_cast<float>(windowSize.x) / static_cast<float>(tilesAmount.x);
	const float _tileHeight = static_cast<float>(windowSize.y) / static_cast<float>(tilesAmount.y);

	TileSize = Vector2f(_tileWidth, _tileHeight);

	bool _color = false;

	for (int _posX = 0; _posX < tilesAmount.x; _posX++)
	{
		for (int _posY = 0; _posY < tilesAmount.y; _posY++)
		{
			RectangleShape* _rectangle = new RectangleShape(Vector2f(_tileWidth, _tileHeight));
			_rectangle->setPosition(Vector2f(_posX * _tileWidth, _posY * _tileHeight));
			_rectangle->setFillColor(_color ? Color::Green : Color(20, 100, 20));
			_color = !_color;
			tiles.push_back(_rectangle);
		}
	}
}

vector<Drawable*> Grid::GetDrawables()
{
	vector<Drawable*> _drawables;
	for (RectangleShape* _tile : tiles)
	{
		_drawables.push_back(_tile);
	}
	return _drawables;
}
