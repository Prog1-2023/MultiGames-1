#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Game
{
	RenderWindow window;
	Vector2f windowSize;
	string name;
	vector<Drawable*> drawables;

public : 
	Vector2f GetWindowSize() const
	{
		return windowSize;
	}

public :
	Game();

private :
	void Start();

	void InitWindow();

	void Update();
	void UpdateWindow();
	void UpdateInputs(const Event& _event);
	void UpdateEvents();
	void Stop();

public :
	void Launch();
};

