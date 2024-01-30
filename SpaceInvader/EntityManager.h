#pragma once
#include "Singleton.h"
#include "IManager.h"
#include "Entity.h"

class EntityManager : public Singleton<EntityManager>, public IManager<int,Entity>
{

};

