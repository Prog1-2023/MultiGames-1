#pragma once
#include "Entity.h"
#include <string>

using namespace std;

class Player : public Entity
{
	//MovementComponent* movement;
	//CollisionComponent* collision;

	//bool isAlive; ?

public:
	/*MovementComponent* GetMovement() const
	{
		return movement;
	}*/
	/*CollisionComponent* GetCollision() const
	{
		return collision;
	}*/
	/*bool GetIsAlive() const
	{
		return isAlive;
	}*/

public:
	Player(const string& _name, const EntityType& _type, const bool _isAlive, const Vector2f& _position, const Vector2f _size, const string& _path);

public:
	void Move();
	virtual void Update() override;
};

