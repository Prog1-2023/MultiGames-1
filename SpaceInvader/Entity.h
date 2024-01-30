#pragma once
#include <SFML/Graphics.hpp>
#include "IManagable.h"
#include "MovementComponent.h"

using namespace sf;

enum EntityType
{
	ENTITY_NONE, ENTITY_STARSHIP, ENTITY_INVADER
};

class Entity : public IManagable<int>
{
	Shape* shape;
	EntityType type;
	MovementComponent* movement;

public:
	Shape* GetShape() const
	{
		return shape;
	}
	EntityType GetEntityType() const
	{
		return type;
	}

public:
	Entity(const int _id,Shape* _shape, const EntityType _type);

public:
	virtual void Register() override;
};

