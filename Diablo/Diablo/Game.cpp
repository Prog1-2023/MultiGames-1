#include "Game.h"
#include "EntityManager.h"
#include "TextureManager.h"

#define PATH_PLAYER "Fichier/Player.png"


Game::Game()
{
	windowSize = Vector2f(1200.0f, 800.0f);
	name = "Diablo";
	player = new Player("Joueur", ENTITY_PLAYER, 10, Vector2f(50.0f, 100.0f), 0.1f);
	drawables = vector<Drawable*>();
}

Game::~Game()
{
	delete player;
}

void Game::Start()
{
	InitWindow();
	InitTextures();
	InitInputs();
	InitMenu();
}

void Game::InitWindow()
{
	window.create(VideoMode(static_cast<unsigned>(windowSize.x), static_cast<unsigned>(windowSize.y)), name);

	InitTextures();
}

void Game::InitMenu()
{
	vector<MenuElement*> _elements{

		new Button("Jouer", "Fichier/Pacifico.ttf", [&]() {MenuManager::GetInstance().GetSelected()->SetWantsToQuit(true); }, Vector2f(600.0f, 450.0f)),
		new Button("Quitter", "Fichier/Pacifico.ttf", [&]() {Stop(); }, Vector2f(600.0f, 590.0f)),

	};
	new Menu("Main", "Fichier/Menu.jpg", _elements);
}

void Game::InitTextures()
{
	TextureManager::GetInstance().Load(player->GetShape(), PATH_PLAYER);
}

void Game::InitInputs()
{
	inputs.AddKeybinds(Keyboard::Q, [&]() {player->MoveLeft(); });
	inputs.AddKeybinds(Keyboard::D, [&]() {player->MoveRight(); });
	inputs.AddKeybinds(Keyboard::Z, [&]() {player->MoveUp(); });
	inputs.AddKeybinds(Keyboard::S, [&]() {player->MoveDown(); });
}


void Game::Update()
{
	MenuManager::GetInstance().Get("Main")->Open(window);

	while (window.isOpen())
	{
		UpdateEvents();
		EntityManager::GetInstance().Update();

	}
}

void Game::UpdateEvents()
{
	Event _event;
	while (window.pollEvent(_event))
	{
		if (_event.type == Event::Closed)
		{
			Stop();
		}

	}
}



void Game::UpdateWindow()
{
	window.clear();
	for (const Drawable* _drawable : drawables)
	{
		window.draw(*_drawable);
	}

	window.display();
}

void Game::Stop()
{
	window.close();
	cout << "C'est la fin de " << name << " !" << endl;
}

void Game::Launch()
{
	Start();
	Update();
}

