#pragma once

#include "IManagable.h"
//#include "CollisionComponent.h"
#include "EntityType.h"

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class EntityManager;

class Entity : public IManagable<string>
{
	EntityType type;

protected:
	Shape* shape;
	int TileAround;

private:
	CollisionComponent* collision;	

public:
	EntityType GetType()const
	{
		return type;
	}

	Vector2f GetPosition()const
	{
		return shape->getPosition();
	}

	Shape* GetShape()const
	{
		return shape;
	}

public:
	Entity(const string& _name, const EntityType& _type);







};

