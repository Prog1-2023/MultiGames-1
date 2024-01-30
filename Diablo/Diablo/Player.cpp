#include "Player.h"

Player::Player(const string& _name, const EntityType& _type, const int _life, const Vector2f& _size, const float _speed) : Entity(_name, _type, _life, _size, _speed)
{
}

void Player::MoveLeft()
{
	shape->move(-speed, 0);
}

void Player::MoveRight()
{
	shape->move(speed, 0);
}

void Player::MoveUp()
{
	shape->move(0, -speed);
}

void Player::MoveDown()
{
	shape->move(0, speed);
}
