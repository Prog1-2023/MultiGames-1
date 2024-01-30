#pragma once

#include "Entity.h"

class Tower : public Entity
{
	float detectionRadius;
	float damages;

public:
	Tower(const string _id, const Vector2f& _position, const Vector2f& _size, const float _detectionRadius, const float _damages, const string& _texturePath);

public:
	virtual void Update() override;
};