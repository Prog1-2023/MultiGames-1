#include "Card.h"

Card::Card(const string& _name, const Vector2f& _size, const string& _path) : Entity(_name, _size)
{
	shape = new RectangleShape(_size);
	//TextureManager::GetInstance()->LoadTexture(_path);
}
