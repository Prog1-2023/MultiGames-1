#pragma once
#include "Map.h"
#include "Singleton.h"
#include "IManager.h"

class MapManager : public Singleton<MapManager>, public IManager<int, Map>
{

};
