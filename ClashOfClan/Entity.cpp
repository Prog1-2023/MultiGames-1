#include "Entity.h"

Entity::Entity(const string& _name) : IManagable(_name)
{
	shape = new RectangleShape();
}

Entity::~Entity()
{
	delete shape;
}
