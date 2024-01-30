#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"

using namespace sf;

class Game
{
	RenderWindow window;
	string name;
public:
	Game();
private:
	void Start();
	void Update();
	void End();
public:
	void Launch();
};

