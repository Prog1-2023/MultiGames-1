#include "EntityManager.h"

void EntityManager::Update()
{
	for (auto _pair : allValues)
	{
		_pair.second->Update();
	}
}

vector<Entity*> EntityManager::GetAllEntites()
{
	vector<Entity*> _entities;
	for (auto _pair : allValues)
	{
		_entities.push_back(_pair.second);
	}
	return _entities;
}
