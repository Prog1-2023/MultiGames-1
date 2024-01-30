#include "Game.h"
#include "Map.h"
#include "MapManager.h"
#include "Entity.h"
#include "EntityManager.h"

Game::Game()
{
	windowSize = Vector2f(1000, 800);
	name = "Mario";
	drawables = vector<Drawable*>();
	inputs = vector<InputManager*>();
}

void Game::Start()
{
	InitWindow();
	InitMap();
}

void Game::InitWindow()
{
	window.create(VideoMode(static_cast<unsigned>(windowSize.x),
		static_cast<unsigned>(windowSize.y)), name);
}

void Game::InitMap()
{
	Map* _map = new Map(0);

	_map->Init(windowSize);
	vector<Drawable*> _drawables = _map->GetDrawables();

	drawables.insert(drawables.end(), _drawables.begin(), _drawables.end());
}

void Game::UpdateWindow()
{
	window.clear();
	for (auto& drawable : drawables)
	{
		window.draw(*drawable);
	}
	const map<string, Entity*>& _entities = EntityManager::GetInstance().GetAll();
	for (auto _iteratorStart = _entities.rbegin(); _iteratorStart != _entities.rend(); _iteratorStart++)
	{
		window.draw(*_iteratorStart->second->GetShape());
	}
	window.display();
}

void Game::UpdateEvents()
{
	Event _event;
	while (window.pollEvent(_event))
	{
		if (_event.type == Event::Closed)
		{
			window.close();
		}
		UpdateInputs(_event);
	}
}

void Game::UpdateInputs(const Event& _event)
{
	for (auto& input : inputs)
	{
		input->Update(_event); // TODO
	}
}

void Game::Update()
{
	while (window.isOpen())
	{
		UpdateEvents();

		MapManager::GetInstance().GetCurrent()->Update();
		EntityManager::GetInstance().Update();
		UpdateWindow(); // draws the window with clear, draw, update
	}
}

void Game::Stop()
{
	cout << "Game stop." << endl;
}

void Game::Launch()
{
	Start();
	Update();
	Stop();
}

