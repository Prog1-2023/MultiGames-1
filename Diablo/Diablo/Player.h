#pragma once
#include"Entity.h"
#include<vector>

class Player : public Entity
{
public:
	Player(const string& _name, const EntityType& _type, const int _life, const Vector2f& _size, const float _speed);

public:
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
};

