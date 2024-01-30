#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Ship.h"
#include "Alien.h"



using namespace std;	
using namespace sf;

class Game
{
	vector<Drawable*> drawables;
	RenderWindow window;
	Ship* ship;
	vector<Alien*> aliens;




public:
	Game();

public:
	void Launch();
private:
	void Start();
	void Update();
	void Stop();
	void InitWindow();
	void UpdateWindow();
};

