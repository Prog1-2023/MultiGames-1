#pragma once
#include <SFML/Graphics.hpp>

struct KeyPressedData
{
	bool leftIsPressed;
	bool rightIsPressed;
};

struct MovementKey
{
	sf::Keyboard::Key left;
	sf::Keyboard::Key right;
};

class MovementComponent
{
	MovementKey keys;
	KeyPressedData boolKeyData;

public:
	MovementComponent(const MovementKey& _keys, const KeyPressedData& _boolKeyData);



};

