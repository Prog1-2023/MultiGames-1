#include "Game.h"
#define WIDTH 800
#define HEIGHT 600

Game::Game()
{
	name = "Sims";
	windowSize = Vector2f(WIDTH, HEIGHT);
}

void Game::Launch()
{
	Start();
	Update();
}

void Game::Start()
{
	Init();
}

void Game::Init()
{
	InitWindow();
}

void Game::InitWindow()
{
	window.create(VideoMode(static_cast<unsigned>(windowSize.x),
							static_cast<unsigned>(windowSize.y)),name);
}

void Game::Update()
{
	while (window.isOpen())
	{
		UpdateEvents();
		UpdateWindow();
	}
}

void Game::UpdateEvents()
{
	Event _event;
	while (window.pollEvent(_event)) {
		if (_event.type == Event::Closed) Stop();

		UpdateInputs(_event);
	}
}

void Game::UpdateInputs(const Event& _event)
{
	if (_event.type == Event::KeyPressed)
	{
		if (_event.key.code == Keyboard::Space) { 
			cout << "Bonne Chance !" << endl;
		}
	}
}

void Game::UpdateWindow()
{
	window.clear();
	for (Drawable* _drawable : drawables) {
		window.draw(*_drawable);
	}
	window.display();
}

void Game::Stop() 
{
	window.close();
	system("cls");
	cout << "C'est la fin des " << name << endl;
}

