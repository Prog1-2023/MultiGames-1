#pragma once
#include "IManager.h"
#include "Singleton.h"
#include "Entity.h"
#include <string>
#include <vector>

using namespace std;

class EntityManager : public Singleton<EntityManager>, public IManager<string, Entity>
{

public:
	vector<Entity*> GetAllEntities()
	{
		vector<Entity*> entities;
		for (auto _pair : allValues)
		{
			entities.push_back(_pair.second);
		}
		return entities;
	}

public:

	void Update();
};
