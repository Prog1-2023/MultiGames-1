#include "Game.h"
#include "EntityManager.h"

Game::Game()
{

}

void Game::Start()
{
	window.create(sf::VideoMode(900, 600), "LaHessFighter", sf::Style::Default & !sf::Style::Resize);
	background = sf::RectangleShape({900,600});
}

void Game::Stop()
{
	window.close();
}

void Game::Update()
{
	while (window.isOpen())
	{
		sf::Event _event;
		while (window.pollEvent(_event))
		{
			switch (_event.type)
			{
			case sf::Event::Closed:
				Stop();
				break;
			default:
				break;
			}
		}

		window.clear();


		auto _allEntities = EntityManager::GetInstance().GetAllEntities();
		for (const auto& _entity : _allEntities)
		{
			window.draw(*_entity->GetShape());
		}
		window.draw(background);

		window.display();
	}
}
