#include "Game.h"

#define SCREEN_WIDTH 2540
#define SCREEN_HEIGHT 1440

#define PATH_PLAYER "Assets/Textures/Player.png"

Game::Game()
{
	windowSize = Vector2f(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f);
	name = "Flappy Bird";
}

void Game::Launch()
{
	Start();
	Update();
}

void Game::Start()
{
	window.create(VideoMode(static_cast<unsigned>(windowSize.x) , static_cast<unsigned>(windowSize.y)), name);

}

void Game::InitEntity()
{
	new Player("Player", ENTITY_PLAYER, true, Vector2f(SCREEN_WIDTH /4.0f, SCREEN_HEIGHT / 4.0f), Vector2f(100.0f, 100.0f), PATH_PLAYER);
}

void Game::Update()
{
	while (window.isOpen())
	{
		Event _event;
		while (window.pollEvent(_event))
		{
			UpdateEvent(_event);
			EntityManager::GetInstance()->Update();
		}
		UpdateDraw();
	}
}

void Game::UpdateEvent(const Event& _event)
{
	if (_event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
	{
		Stop();
	}
}

void Game::UpdateDraw()
{
	window.clear();
	for (Entity* _entity : EntityManager::GetInstance()->GetAllEntities())
	{
		window.draw(*_entity->GetShape());
	}
	window.display();
}

void Game::Stop()
{
	cout << "fin de " << name << endl;
	window.close();
}
