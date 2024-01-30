#include "Entity.h"

Entity::Entity(const string& _name, const EntityType& _type) : IManagable(_name)
{
	type = _type;

}
