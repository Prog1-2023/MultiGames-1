#pragma once
#include "Singleton.h"
#include <vector>
#include "Entity.h"

class EntityManager : public Singleton<EntityManager>
{
	std::vector<Entity*> allEntities;

public:
	~EntityManager();

public:
	void AddEntity(Entity* _toAdd);
	int GetEntityIndex(Entity* _toSearch);
	std::vector<Entity*> GetAllEntities();


};

