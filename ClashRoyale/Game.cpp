#include "Game.h"

Game::Game()
{
	windowSize = Vector2f(800.0f, 900.0f);
	name = "ClashRoyale";
	drawables = vector<Drawable*>();
}

void Game::Launch()
{
	Start();
	Update();
	Stop();
}

void Game::Start()
{
	InitWindow();
}

void Game::InitWindow()
{
	window.create(VideoMode(static_cast<int>(windowSize.x), static_cast<int>(windowSize.y)), name);
}

void Game::Update()
{
	while (window.isOpen())
	{
		UpdateEvents();
	}
}

void Game::UpdateWindow()
{
	window.clear();

	for (const Drawable* _drawable : drawables)
	{
		window.draw(*_drawable);
	}

	window.display();
}

void Game::UpdateInputs(const Event& _event)
{
	//TODO
}

void Game::UpdateEvents()
{
	Event _event;
	while (window.pollEvent(_event))
	{
		if (_event.type == Event::Closed)
		{
			Stop();
		}
	}

	UpdateInputs(_event);
}

void Game::Stop()
{
	window.close();
	cout << "C'est la fin de " << name << " ! " << endl;
}
