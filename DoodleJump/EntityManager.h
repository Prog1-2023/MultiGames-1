#pragma once
#include "Entity.h"
#include "Singleton.h"
#include "IManager.h"

class EntityManager : public Singleton<EntityManager>, public IManager<string, Entity>
{
public:
	void Update();
	bool IsAvailable(const Vector2f& _position, const Vector2f& _size);


};

