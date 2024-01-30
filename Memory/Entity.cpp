#include "Entity.h"



Entity::Entity(const string& _name, const Vector2f& _size) : IManagable(_name)
{
	shape = new RectangleShape(_size);
}
