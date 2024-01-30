#pragma once
#include "Singleton.h"
#include "IManager.h"
#include "Map.h"

class MapManager : public Singleton<MapManager>, public IManager<int, Map>
{

};

