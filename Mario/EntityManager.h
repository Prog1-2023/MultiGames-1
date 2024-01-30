#pragma once
#include <iostream>

#include "IManager.h"
#include "Singleton.h"
#include "Entity.h"

using namespace std;

class EntityManager : public Singleton<EntityManager>, public IManager<string, Entity>
{
public:
    static EntityManager& GetInstance()
    {
        static EntityManager instance;
        return instance;
    }

public:
    void Update();
};

