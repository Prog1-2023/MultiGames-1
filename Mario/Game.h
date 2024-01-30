#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

#include "InputManager.h"

using namespace sf;
using namespace std;

class Game
{
	vector<Drawable*> drawables;
	vector<InputManager*> inputs;

	RenderWindow window;
	Vector2f windowSize;
	string name;

public:
	Game();
private:
	void Start();
	void InitWindow();
	void InitMap();
	void UpdateWindow();
	void UpdateEvents();
	void UpdateInputs(const Event& _event);
	void Update();
	void Stop();
public:
	void Launch();

};

