#include "Entity.h"
#include "EntityManager.h"

Entity::Entity(const int _id, Shape* _shape, const EntityType _type)
	: IManagable(_id)
{
	shape = _shape;
	type = _type;
	movement = new MovementComponent();

	Register();
}

void Entity::Register()
{
	EntityManager::GetInstance().Add(id, this);
}
