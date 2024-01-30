#include "EntityManager.h"

void EntityManager::UpdateAll()
{
	for (const auto& _pair : allValues)
	{
		_pair.second->Update();
	}
}
vector<Drawable*> EntityManager::GetAllDrawables()
{
	vector<Drawable*> _drawables;
	for (const auto& _pair : allValues)
	{
		_drawables.push_back(_pair.second->GetShape());
	}
	return _drawables;
}

