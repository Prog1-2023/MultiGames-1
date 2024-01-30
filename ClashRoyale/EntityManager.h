#pragma once
#include"Singleton.h"
#include"Entity.h"
#include"IManager.h"
#include<map>
#include<string>

using namespace std;

class EntityManager : public Singleton<EntityManager>, public IManager<string, Entity>
{
public:
    void Update();
    bool isAvailable(const Vector2f& _position, const Vector2f _size);
};