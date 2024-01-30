#include "Building.h"

Building::Building(const string& _name, const BuildingType& _type) : Entity(_name)
{
	type = _type;
}
