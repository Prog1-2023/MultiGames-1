#pragma once
#include "IManagable.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Entity : public IManagable<string>
{
	Shape* shape;

public:
	Entity(const string& _name);
	~Entity();
};

