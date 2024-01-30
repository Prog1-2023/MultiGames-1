#include "Game.h"

Game::Game()
{
	window = new RenderWindow();

	player = new Starship(0,new RectangleShape({50.0f, 50.0f}));

	invaders = vector<Invader*>();

	drawables = vector<Drawable*>();
}

void Game::Launch()
{
	window->create(VideoMode(SCREEN_WIDGT, SCREEN_HIGHT), "Space Invader");
	InitDrawable();

	Update();
}

void Game::InitInvaders()
{

}

//Initialisation des Drawables (Player + invaders)
void Game::InitDrawable()
{
	drawables.push_back(player->GetShape());

	for (Invader* _invader : invaders)
	{
		drawables.push_back(_invader->GetShape());
	}
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
				Close();
			}
		}
		Display();
	}
}

void Game::Display()
{
	window->clear(Color::Black);

	for (Drawable* _drawable : drawables)
	{
		window->draw(*_drawable);
	}

	window->display();
}

void Game::Close()
{
	window->close();
	cout << "Jeu terminé !" << endl;
}
