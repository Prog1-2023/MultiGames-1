#include "Game.h"

Game::Game()
{
	windowSize = Vector2f(1200.0f, 800.0f);
	name = "GameOfLife";
	drawables = vector<Drawable*>();
}

void Game::InitWindow()
{
	window.create(VideoMode(static_cast<unsigned>(windowSize.x), static_cast<unsigned>(windowSize.y)), name);
}

void Game::InitMap()
{
}

void Game::UpdateWindow()
{
}

void Game::MainUpdate()
{
	while (window.isOpen())
	{
		UpdateWindow();
		UpdateEntities();
		UpdateEntities();
	}
}

void Game::UpdateEvent()
{
}

void Game::UpdateEntities()
{
	
}

void Game::UpdateInputs(const Event& _event)
{

}

void Game::Launch()
{
	Start();
	MainUpdate();
}

void Game::Start()
{
	InitWindow();
	InitMap();
}

void Game::Stop()
{
	cout << "Fin du jeu " << endl;
}
