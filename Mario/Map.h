#pragma once
#include "Entity.h"
#include "Block.h"
#include "IManagable.h"

#include <vector>

using namespace std;

class Map : public IManagable<int>
{
	vector<vector<Entity*>> map;

	// Bonne chance X)

	vector<Entity*> entities;
	vector<Entity*> builds;

	int entityCount;
	int buildCount;

public:
	vector<Drawable*> GetDrawables()
	{
		vector<Drawable*> _drawables;

		for (auto _entity : entities)
		{
			_drawables.push_back(_entity->GetShape());
		}
		for (auto _build : builds)
		{
			_drawables.push_back(_build->GetShape());
		}
		return _drawables;
	}

public:
	Map(const int _id);
public:
	void Init(const Vector2f& _windowSize);
	virtual void Register() override;
	void Update();
};


