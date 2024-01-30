#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

static Vector2f GetRandomPosition(const Vector2f& _min, const Vector2f& _max)
{
	return Vector2f(
		_min.x + static_cast<float>(rand()) / RAND_MAX * (_max.x - _min.x),
		_min.y + static_cast<float>(rand()) / RAND_MAX * (_max.y - _min.y)
	);
}