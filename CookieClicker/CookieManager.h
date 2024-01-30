#pragma once
#include "Singleton.h"
#include "IManager.h"
#include "Cookie.h"

class CookieManager : public Singleton<CookieManager>, public IManager<int, Cookie>
{
public:
	bool HasHit(const Vector2i& _position);
};