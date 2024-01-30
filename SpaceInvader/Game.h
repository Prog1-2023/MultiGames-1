#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Starship.h"
#include "Invader.h"

using namespace std;
using namespace sf;

///DEPLACER SI BESOIN///
#define SCREEN_WIDGT 1000
#define SCREEN_HIGHT 700

class Game
{
	RenderWindow* window;

	Starship* player;

	vector<Invader*> invaders;

	vector<Drawable*> drawables;


public:
	Game();
public:
	void Launch();
	void InitInvaders();
	void InitDrawable();

	void Update();

	void Display();
	void Close();
};

