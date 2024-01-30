#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Game
{
	RenderWindow window;

	Shape* shape;
	Texture* texture;

public:
	Game();

public:
	void Launch();

private:
	void Start();
	void Update();
	void Stop();
	void UpdateWindow();
};

