#include "Spawner.h"
#include "Timer.h"
#include "CookieManager.h"
#include "Macro.h"

Spawner::Spawner(const Vector2f& _min, const Vector2f& _max)
{
	min = _min;
	max = _max;
	id = 0;
}


void Spawner::SpawnCookie()
{
	const Vector2f& _position = GetRandomPosition(min, max);
	const int _id = CookieManager::GetInstance().Count();
	new Cookie(_id, _position);
}

void Spawner::Init()
{
	id++;
	SpawnCookie();
	new Timer(id, [this]() { SpawnCookie(); }, 3.0f, DURATION_SECONDS, true);
}