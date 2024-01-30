#pragma once
#include "Entity.h"
#include "Type.h"

class Building : public Entity
{
	BuildingType type;

public:
	Building(const string& _name, const BuildingType& _type);
};