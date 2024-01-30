#pragma once
#include <SFML/Graphics.hpp>
#include "DirectionType.h"

using namespace sf;

class MovementComponent
{
	float speed;
	DirectionType direction;
};

