#include "Game.h"
#include "Macro.h"

Game::Game()
{
	InitWindow();
	ship = new Ship();
	aliens = vector<Alien*>();
	drawables = vector<Drawable*>();
}

void Game::InitWindow()
{
	window.create(VideoMode( 800 /*SCREEN_WIDTH*/, 600 /*SCREEN_HEIGHT*/), "Shoot Them Up"); //Macro non fonctionelle?
}

void Game::UpdateWindow()
{
	Event _event;
	while (window.pollEvent(_event))
	{
		if (_event.type == Event::Closed) Stop();
	}
}

void Game::Launch()
{
	Start();
	Update();
	Stop();
}

void Game::Start()
{

	for (Alien* _alien : aliens)
	{
		drawables.push_back(_alien->GetShape());
	}
	drawables.push_back(ship->GetShape());
}

void Game::Update()
{
	while (window.isOpen())
	{
		UpdateWindow();
	}
}

void Game::Stop()
{
	window.close();
	system("cls");
}

