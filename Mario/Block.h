#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;


class Block
{
	RectangleShape* shape;


public:
	Shape* GetShape()
	{
		return shape;
	}
};

