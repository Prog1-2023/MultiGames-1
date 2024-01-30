#include "MovementComponent.h"
#include "EntityManager.h"

MovementComponent::MovementComponent()
{
	canMove = true;
	velocity = 3.0f;
	directionData = DirectionData();
	reactions = vector<CollisionReaction>();
}

MovementComponent::MovementComponent(const float _velocity, const DirectionType& _type, const bool _canMove, const vector<CollisionReaction>& _reactions)
{
	canMove = _canMove;
	velocity = _velocity;
	directionData = DirectionData(_type);
	reactions = _reactions;
}

void MovementComponent::Move(CollisionComponent* _collision, Entity* _entity)
{
	if (!canMove) return;

	TryToMove(_collision, _entity, directionData);
}

void MovementComponent::TryToMove(CollisionComponent* _collision, Entity* _entity, const DirectionData& _directionData)
{
	if (!canMove) return;

	const Vector2f& _destination = _directionData.direction * velocity;
	Shape* _shape = _entity->GetShape();
	_shape->move(_destination);


	if (_collision->CheckCollision(_entity, reactions))
	{
		_shape->move(-_destination);
	}
}
