#pragma once
#include "IManagable.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Cookie : public IManagable<int>
{
	Shape* shape;

public:
	FloatRect GetGlobalBounds() const
	{
		return shape->getGlobalBounds();
	}
	Shape* GetShape() const
	{
		return shape;
	}

public:
	Cookie(const int _id, const Vector2f& _position);
	~Cookie();

private:
	virtual void Register() override;
};