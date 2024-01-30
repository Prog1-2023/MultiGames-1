#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "CollisionComponent.h"
using namespace sf;

enum DirectionType
{
	DIRECTION_NONE,
	DIRECTION_LEFT,
	DIRECTION_RIGHT,
};

struct DirectionData
{
	Vector2f direction;
	DirectionType type;

	DirectionData()
	{
		direction = Vector2f();
		type = DIRECTION_NONE;
	}

	DirectionData(const DirectionType& _type)
	{
		SetDirectionType(_type);
	}

private:
	Vector2f GetDirectionByType(const DirectionType& _direction)
	{
		Vector2f direction[] = {
			Vector2f(0.0f, 0.0f),
			Vector2f(-1.0f, 0.0f),
			Vector2f(-1.0f, -1.0f),
			Vector2f(0.0f, -1.0f),
			Vector2f(1.0f, -1.0f),
			Vector2f(1.0f, 0.0f),
			Vector2f(1.0f, 1.0f),
			Vector2f(0.0f, 1.0f),
			Vector2f(-1.0f, 1.0f),
		};

		return direction[_direction];
	}

public:

	void SetDirectionType(const DirectionType& _type)
	{
		direction = GetDirectionByType(_type);
		type = _type;
	}

	void AddDirection(const DirectionType& _type)
	{
		direction += GetDirectionByType(_type);
	}

	void SetDirection(const DirectionType& _type)
	{
		direction = GetDirectionByType(_type);
	}
};

class MovementComponent
{
	bool canMove;
	float velocity;
	DirectionData directionData;
	vector<CollisionReaction> reactions;
	vector<Entity*> allEntities;

public:
	void SetCanMove(const bool _status)
	{
		canMove = _status;
	}
	DirectionData& GetDirectionData()
	{
		return directionData;
	}
	DirectionType GetType() const
	{
		return directionData.type;
	}

public:
	MovementComponent();
	MovementComponent(const float _velocity, const DirectionType& _direction, const bool _canMove = true, const vector<CollisionReaction>& _reactions = vector<CollisionReaction>());

public:
	void Move(CollisionComponent* _collision, Entity* _entity);
	void TryToMove(CollisionComponent* _collision, Entity* _entity, const DirectionData& _directionData);
};

