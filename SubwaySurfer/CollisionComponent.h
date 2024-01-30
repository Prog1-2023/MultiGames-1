#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <functional>

using namespace std;
using namespace sf;

enum EntityType;
class Entity;

struct CollisionReaction
{
	EntityType type;

	function<void(Shape* _shape)> callbacks;

	CollisionReaction(const EntityType& _type, const function<void(Shape* _shape)>& _callbacks)
	{
		type = _type;
		callbacks = _callbacks;
	}
};

class CollisionComponent
{
	Shape* currentShape;

public:
	bool CheckCollision(Entity* _currentEntity, const vector<CollisionReaction>& _reactions);
};

