#pragma once
#include "Entity.h"

class Card : public Entity
{
public:
	void SetPosition(const Vector2f& _position)
	{
		shape->setPosition(_position);
	}
public:
	Card(const string& _name, const Vector2f& _size, const string& _path);
};

