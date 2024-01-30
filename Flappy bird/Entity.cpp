#include "EntityManager.h"

Entity::Entity(const string& _name, const EntityType& _type, const bool _isAlive, const Vector2f& _position, const Vector2f& _size, const string& _path) : IManagable(_name)
{

	type = _type;
	position = _position;
	shape = new RectangleShape(_size);
	isAlive = _isAlive;

	shape->setPosition(_position);
	InitTexture(_path);
	Register();

}

Entity::~Entity()
{
	delete shape;
}

void Entity::Register()
{
	EntityManager::GetInstance()->Add(id, this);
}

void Entity::InitTexture(const string& _path)
{
	TextureManager::GetInstance()->Load(shape, _path);
}

void Entity::Update()
{

}

Vector2f operator*(Vector2f _first, Vector2f _second)
{
	return Vector2f(_first.x * _second.x, _first.y * _second.y);
}