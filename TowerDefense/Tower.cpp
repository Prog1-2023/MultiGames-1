#include "Tower.h"
#include "TextureManager.h"

Tower::Tower(const string _id, const Vector2f& _position, const Vector2f& _size, const float _detectionRadius, const float _damages, const string& _texturePath) : Entity(_id)
{
	shape = new CircleShape(_size.x / 2);
	TextureManager::GetInstance()->LoadTexture(shape, _texturePath);
	shape->setPosition(_position);
}

void Tower::Update()
{
	cout << "Updated!" << endl;
}
