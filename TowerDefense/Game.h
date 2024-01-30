#pragma once

#include "EntityManager.h"
#include "Tower.h"
#include "Grid.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Game
{
	Vector2i windowSize;
	RenderWindow* window;
	Grid* grid;

public:
	Game();
	~Game();

private:
	void Start();
	void Inits();
	void InitWindow();
	void InitGrid();
	void Update();
	void UpdateWindow();
	void UpdateEvents();
	void Stop();

public:
	void Launch();
};