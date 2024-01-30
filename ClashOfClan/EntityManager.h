#pragma once
#include "Singleton.h"
#include "IManager.h"
#include "Entity.h"

using namespace std;

class EntityManager : public Singleton<EntityManager>, public IManager<string, Entity>
{
};