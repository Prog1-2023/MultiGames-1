#include "Entity.h"
#include "Macro.h"
#include "EntityManager.h"


Entity::Entity(const string& _name, const EntityType& _type, const Vector2f& _position, const Vector2f& _size, const string& _path) : IManagable(_name)
{
	type = _type;
	shape = nullptr;
	shape = new RectangleShape(_size);
	shape->setPosition(_position);
	SetOriginAtMiddle(shape);

	Register();

}

Entity::~Entity()
{
	delete shape;
}

void Entity::Register()
{
	EntityManager::GetInstance().Add(id, this);

}

void Entity::Update()
{
}