#include "EntityManager.h"

#include "EntityManager.h"

void EntityManager::Update()
{
	for (auto& _pair : allValues)
	{
		_pair.second->Update();
	}
}
