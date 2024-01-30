#pragma once
#include "Spawner.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

class Game
{
	Spawner* spawner;
	RenderWindow window;
	int score;

public:
	Game();
	~Game();

private:
	void Start();
	void Update();
	void UpdateInputs(const Event& _event);
	void UpdateWindow();
	void Stop();

public:
	void Launch();
};