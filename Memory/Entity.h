#pragma once
#include "IManagable.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Entity : public IManagable<string>
{
protected:
	Shape* shape;

public:
	Entity(const string& _name, const Vector2f& _size);
};