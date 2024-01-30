#include "Game.h"

#define PATH_ZELDO "Assets/zeldoRB.png"

Game::Game()
{
	shape = new RectangleShape(Vector2f(1050.0f, 550.0f));
	texture = new Texture();

	if (!texture->loadFromFile(PATH_ZELDO))
	{
		
	}

	shape->setTexture(texture);
}

void Game::Launch()
{
	Start();
	Update();
	Stop();
}

void Game::Start()
{
	window.create(VideoMode(1200, 800), "ZELDOOOOO");
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
		UpdateWindow();
	}
}

void Game::Stop()
{
	window.close();
}

void Game::UpdateWindow()
{
	window.clear();

	window.draw(*shape);

	window.display();
}
