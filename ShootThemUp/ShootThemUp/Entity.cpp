#include "Entity.h"


Entity::Entity(const char _id, const EntityType& _type, const Vector2f& _position, const float _speed) : IManagable(_id)
{
	type = _type;
	shape = nullptr;
	position = _position;
	shape = new RectangleShape();
	shape->setPosition(_position);
}

Entity::~Entity()
{
	delete shape;
}
