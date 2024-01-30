#include "EntityManager.h"

void EntityManager::Update()
{
	for (auto _pair : allValues)
	{
		_pair.second->Update();
	}
}

bool EntityManager::isAvailable(const Vector2f& _position, const Vector2f _size)
{
	const FloatRect& _rect = FloatRect(_position - (_size / 20.0f), _size);

	for (auto _pair : allValues)
	{
		if (_pair.second->GetShape()->getLocalBounds().intersects(_rect)) return true;
	}

	return false;
}
