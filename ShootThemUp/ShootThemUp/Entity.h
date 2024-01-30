#pragma once
#include <SFML/Graphics.hpp>
#include "IManagable.h"
#include "EntityType.h"

using namespace sf;

class Entity : public IManagable<char>
{
	EntityType type;
protected:
	RectangleShape* shape;
	Vector2f position;
	float speed;

public:
	Shape* GetShape() const
	{
		return shape;
	}
	Vector2f GetPosition() const
	{
		return position;
	}
	Shape* GetShape() const
	{
		return shape;
	}

public:
	Entity(const char _id, const EntityType& _type, const Vector2f& _position, const float _speed);
	~Entity();
};

