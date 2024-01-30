#include "Game.h"
#include "EntityManager.h"
#include "InputManager.h"

Game::Game()
{
	window = new RenderWindow();
}

Game::~Game()
{
	delete window;
}

void Game::Start()
{
	window->create(VideoMode(800, 600), "Subway Surfer");
	InitPlayer();
}

void Game::InitPlayer()
{
	const Vector2f& _position = Vector2f(window->getSize());
	const Vector2f& _size = Vector2f(100.f,100.f);
	new Player("Player", Vector2f(_position.x / 2.f, _position.y / 2.f), _size);
}

void Game::Update()
{
	while (window->isOpen())
	{
		Event _event;
		while (window->pollEvent(_event))
		{
			if (_event.type == Event::Closed)
			{
				window->close();
			}
			InputManager::GetInstance()->ExecuteActions(_event);
		}
		
		EntityManager::GetInstance()->Update();

		window->clear();
		for (Entity* _entity : EntityManager::GetInstance()->GetAllEntities())
		{
			if (!_entity) return;
			window->draw(*_entity->GetShape());
		}
		window->display();
	}
}

void Game::Stop()
{

}

void Game::Launch()
{
	Start();
	Update();
	Stop();
}
