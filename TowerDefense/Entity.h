#pragma once

#include <SFML/Graphics.hpp>

#include "IManagable.h"

using namespace sf;
using namespace std;

class Entity : public IManagable<string>
{
protected:
	Shape* shape;

public:
	Vector2f GetPosition() const
	{
		return shape->getPosition();
	}
	Shape* GetShape() const
	{
		return shape;
	}

public:
	Entity(const string& _id);
	~Entity();

private:
	virtual void Register() override;

public:
	virtual void Update() = 0;
};