#pragma once
#include "Singleton.h"
#include "IManager.h"
#include "Entity.h"

using namespace std;



class EntityManager : public Singleton<EntityManager>, public IManager<string, Entity>
{
public:
	vector<Entity*> GetAllEntities()
	{
		vector<Entity*> _entities;
		auto _iterator = allValues.begin();

		for (; _iterator != allValues.end(); _iterator++)
		{
			Entity* _entity = _iterator->second;
			_entities.push_back(_entity);
		}
		return _entities;
	}
public:
	void Update();
};

