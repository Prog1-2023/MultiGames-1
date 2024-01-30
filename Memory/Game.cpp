#include "Game.h"

Game::Game()
{
	name = "Memory Game";
}

void Game::Start()
{
	window.create(VideoMode(800, 600), name);
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
				window.close();
			}
		}
		window.clear();
		//window.draw();
		window.display();
	}
}

void Game::End()
{
	cout << "Le jeu est fini ! " << endl;
}

void Game::Launch()
{
	Start();
	Update();
	End();
}
