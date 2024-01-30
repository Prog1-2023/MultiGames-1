#pragma once
#include"IManager.h"
#include"Singleton.h"
#include"Entity.h"
#include<iostream>
#include<map>

using namespace std;

class EntityManager : public Singleton<EntityManager>, public IManager<string, Entity>
{
public:
	void Update();
	vector<Entity*> GetAllEntites();
};

