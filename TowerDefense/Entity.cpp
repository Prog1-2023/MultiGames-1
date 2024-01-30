#include "Entity.h"
#include "EntityManager.h"

Entity::Entity(const string& _id) : IManagable(_id)
{
	shape = nullptr;

	Register();
}

Entity::~Entity()
{
	if (shape) delete shape;
}

void Entity::Register()
{
	EntityManager::GetInstance()->Add(id, this);
}