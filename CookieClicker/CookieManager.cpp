#include "CookieManager.h"

bool CookieManager::HasHit(const Vector2i& _position)
{
	for (const auto& _pair : allValues)
	{
		const FloatRect& _bounds = _pair.second->GetGlobalBounds();
		if (_bounds.contains(Vector2f(_position))) return true;
	}

	return false;
}