#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "EntityManager.h"
#include "Player.h"

using namespace std;
using namespace sf;

class Game
{
	RenderWindow window;
	Vector2f windowSize;
	string name;

public:
	Game();

public:
	void Launch();

private:
	void Start();
	void InitEntity();
	void Update();
	void UpdateEvent(const Event& _event);
	void UpdateDraw();
	void Stop();
};

