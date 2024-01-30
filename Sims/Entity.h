#pragma once
#include "IManagable.h"
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;

enum EntityType
{
	ENTITY_NONE,
};

class Entity : public IManagable<string>
{
	EntityType type;
	string name;

private:

	virtual void Register() override;

protected:
	Shape* shape;

public:

	EntityType GetType() const { return type; }
	Shape* GetShape() const { return shape; }

public:
	Entity(const string& _name, const EntityType& _type, const Vector2f& _position,
		const Vector2f& _size, const string& _path);
	~Entity();

public:
	virtual void Update();
};

