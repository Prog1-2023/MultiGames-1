#pragma once
#include "Entity.h"
#include "MovementComponent.h"
#include "CollisionComponent.h"

class Player : public Entity
{
	MovementComponent* movement;
	CollisionComponent* collision;
public:
	Player(const string& _name, const Vector2f& _position, const Vector2f& _size);
	~Player();

private:
	void Loose();
	void Move();
	void InitKeybinds();

public:
	virtual void Update() override;
};

