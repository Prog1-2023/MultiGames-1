#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Game
{
	RenderWindow window;
	Vector2f windowSize;

public:
	Game();
	~Game();

public:
	void Launch();

private:
	void Start();
	void Update();
	void Stop();
	void Draw();
};

