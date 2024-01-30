#include "Game.h"
#include "CookieManager.h"
#include "TimerManager.h"

Game::Game()
{
	spawner = new Spawner(Vector2f(0.0f, 0.0f), Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
	score = 0;
}

Game::~Game()
{
	delete spawner;
}


void Game::Start()
{
	window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Cookie Clicker");
	spawner->Init();
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

			UpdateInputs(_event);
		}

		TimerManager::GetInstance().Update();
		UpdateWindow();
	}
}

void Game::UpdateInputs(const Event& _event)
{
	if (_event.type == Event::MouseButtonPressed)
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (CookieManager::GetInstance().HasHit(Mouse::getPosition(window)))
			{
				cout << "COOKIE !" << endl;
				score++;
			}
		}
	}
}

void Game::UpdateWindow()
{
	window.clear();

	for (const auto& _pair : CookieManager::GetInstance().GetAll())
	{
		window.draw(*_pair.second->GetShape());
	}

	window.display();
}

void Game::Stop()
{
	cout << "Vous avez un score de " << score << endl;
}


void Game::Launch()
{
	Start();
	Update();
	Stop();
}