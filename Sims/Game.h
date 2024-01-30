#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;


class Game
{
	RenderWindow window;
	Vector2f windowSize;
	string name;
	vector<Drawable*> drawables;

private:
	void Start();

	void Init();
	void InitWindow();

	void Update();
	void UpdateEvents();
	void UpdateInputs(const Event& _event);
	void UpdateWindow();

	void Stop();


public:
	Game();

	void Launch();

	Vector2f GetWindowSize() const { return windowSize; }


};

