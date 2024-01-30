#include "Game.h"

Game::Game()
{
	windowSize = Vector2f(1200.0f, 800.0f);
}

Game::~Game()
{
}

void Game::Launch()
{
	Start();
	Update();
	Stop();
}

void Game::Start()
{
	window.create(VideoMode(static_cast<unsigned int>(windowSize.x), static_cast<unsigned int>(windowSize.y)), "Clash Of Clan");
}

void Game::Update()
{
	while (window.isOpen())
	{
		Event _event;
		while (window.pollEvent(_event))
		{
			if (_event.type == Event::Closed)
			{
				Stop();
			}

		}
	}
}

void Game::Stop()
{
	window.close();
}

void Game::Draw()
{
	window.clear();

	//window.draw();

	window.display();
}
