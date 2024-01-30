#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Spawner
{
	Vector2f min;
	Vector2f max;
	int id;

public:
	Spawner(const Vector2f& _min, const Vector2f& _max);

private:
	void SpawnCookie();

public:
	void Init();
};