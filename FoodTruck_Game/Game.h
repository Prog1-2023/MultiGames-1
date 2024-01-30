#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "Map.h"
class Game
{
	RenderWindow window;

	Vector2f windowSize;
	string name;
	vector<Drawable*> drawables;


public:
	Vector2f GetWindowSize() const
	{
		return windowSize;
	}


public:
	Game();

private:
	void InitWindow();
	void InitMap();
private:
	void UpdateWindow();
	void MainUpdate();;
	void UpdateEvent();
	void UpdateEntities();
	void UpdateInputs(const Event& _event);

public:
	void Launch();
private:
	void Start();
	void Stop();


};

