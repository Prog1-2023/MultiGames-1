#include "Map.h"
#include "MapManager.h"

Map::Map(const int _id) : IManagable(_id)
{

}

void Map::Init(const Vector2f& _windowSize)
{
}

void Map::Register()
{
	MapManager::GetInstance().Add(id, this);
}

void Map::Update()
{
	// IL FAUT DEF ENTITY COUNT ET BUILDS COUNT
	for (int _i = 0; _i < entityCount; _i++)
	{
		entities[_i]->Update();
	}
	for (int _i = 0; _i < buildCount; _i++)
	{
		entities[_i]->Update();
	}
}
