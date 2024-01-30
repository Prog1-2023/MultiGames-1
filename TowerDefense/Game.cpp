#include "Game.h"

#define DEBUG_TEXTURE_PATH "Assets/Textures/debug.png"

Game::Game()
{
	window = new RenderWindow();
	grid = nullptr;
}

Game::~Game()
{
	delete window;
	delete grid;
}

void Game::Start()
{
	Inits();

	// TODO temp
	//new Tower("debugTower", Vector2f(0.0f, 0.0f), grid->GetTileSize(), 50.0f, 5.0f, DEBUG_TEXTURE_PATH);
}

void Game::Inits()
{
	InitWindow();
	InitGrid();
}

void Game::InitWindow()
{
	windowSize = Vector2i(800, 800);
	window->create(VideoMode(windowSize.x, windowSize.y), "TowerDefense");
}

void Game::InitGrid()
{
	grid = new Grid(windowSize, Vector2i(15, 15));
	grid->Generate();
}

void Game::Update()
{
	while (window->isOpen())
	{
		EntityManager::GetInstance()->UpdateAll();
		UpdateEvents();
		UpdateWindow();
	}
	Stop();
}

void Game::Stop()
{
	cout << "Tower Defense closed!" << endl;
}

void Game::UpdateWindow()
{
	window->clear();
	#pragma region Draw	
	vector<Drawable*> _drawables = grid->GetDrawables();
	for (Drawable* _drawable : _drawables)
	{
		window->draw(*_drawable);
	}
	_drawables = EntityManager::GetInstance()->GetAllDrawables();
	for (Drawable* _drawable : _drawables)
	{
		window->draw(*_drawable);
	}
	#pragma endregion
	window->display();
}

void Game::UpdateEvents()
{
	Event _event;
	while (window->pollEvent(_event))
	{
		if (_event.type == Event::Closed)
		{
			window->close();
		}
	}
}

void Game::Launch()
{
	Start();
	Update();
}
