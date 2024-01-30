#include "EntityManager.h"
#include <assert.h>

EntityManager::~EntityManager()
{
	for (auto _entity : allEntities)
	{
		delete _entity;
		_entity = nullptr;
	}
}

void EntityManager::AddEntity(Entity* _toAdd)
{
	allEntities.emplace_back(_toAdd);
}

int EntityManager::GetEntityIndex(Entity* _toSearch)
{
	int _i = 0;
	for (const auto& _entity : allEntities)
	{
		if (_entity == _toSearch) return _i;
		_i++;
	}
	
	assert(_i >= 0);
	assert(_i < allEntities.size());
	return -1;
}

std::vector<Entity*> EntityManager::GetAllEntities()
{
	return allEntities;
}
