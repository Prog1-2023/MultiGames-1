#include "Entity.h"

#include "EntityManager.h"
#include "TextureManager.h"

Entity::Entity(const string& _name, const EntityType& _type, const Vector2f& _position, const Vector2f& _size, const string& _path) : IManagable(_name)
{
	Register();

	type = _type;
	position = _position;
	shape = new RectangleShape(Vector2f(_size));
	shape->setPosition(_position);
	InitTexture(_path);
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

void Entity::SetOriginAtMiddle()
{
	shape->setOrigin(shape->getLocalBounds().width / 2, shape->getLocalBounds().height / 2);
}

void Entity::Update()
{
}
