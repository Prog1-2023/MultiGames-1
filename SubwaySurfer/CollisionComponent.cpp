#include "CollisionComponent.h"
#include "EntityManager.h"
#include "Entity.h"

bool CollisionComponent::CheckCollision(Entity* _currentEntity, const vector<CollisionReaction>& _reactions)
{
	Shape* _currentShape = _currentEntity->GetShape();
	const FloatRect& _rect = _currentShape->getGlobalBounds();

	vector<Entity*> _allEntities = EntityManager::GetInstance()->GetAllEntities();

	for (const Entity* _entity : _allEntities)
	{
		Shape* shape = _entity->GetShape();

		//si l'entity est la meme que l'actuelle continue
		if (shape == _currentShape) continue;

		//si l'entity est en collision
		if (_rect.intersects(shape->getGlobalBounds()))
		{
			const EntityType& _entityType = _entity->GetType();
			for (CollisionReaction _reaction : _reactions)
			{
				if (_entityType == _reaction.type)
				{
					_reaction.callbacks(shape);
					return true;
				}
			}
		}
	}

	return false;
}
