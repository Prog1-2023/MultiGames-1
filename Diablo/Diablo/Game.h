#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "InputManager.h"
#include"MenuManager.h"
#include"Player.h"


using namespace std;
using namespace sf;

class Game
{
	RenderWindow window;
	Vector2f windowSize;
	string name;
	Player* player;
	InputManager inputs;
	vector<Drawable*> drawables;

public:
	vector<Drawable*> GetDrawables()const
	{
		vector<Drawable*> _drawables;

		_drawables.push_back(player->GetShape());

		return _drawables;

	}
	Vector2f GetWindowSize() const
	{
		return windowSize;
	}

public:
	Game();
	~Game();

private:
	void Start();
	void InitWindow();
	void InitMenu();
	void InitTextures();
	void InitInputs();
	void Update();
	void UpdateEvents();
	void UpdateWindow();
	void Stop();

public:
	void Launch();
};


