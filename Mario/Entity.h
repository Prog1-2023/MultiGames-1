#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

class Entity 
{
	RectangleShape* shape;
	Vector2f position;

public:
	Shape* GetShape()
	{
		return shape;
	}

public:
	void Update();

};

