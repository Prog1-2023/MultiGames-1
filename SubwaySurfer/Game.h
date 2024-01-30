#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

using namespace sf;

class Game
{
	RenderWindow* window;

public:
	Game();
	~Game();

public:
	void Launch();

private:
	void Start();
	void InitPlayer();
	void Update();
	void Stop();
};

