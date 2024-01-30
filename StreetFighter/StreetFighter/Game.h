#pragma once
#include <SFML/Graphics.hpp>

class Game
{
	sf::RenderWindow window;
	sf::RectangleShape background;
	sf::Texture backgroundTexture;

public:
	Game();

public:
	void Start();
	void Stop();
	void Update();


};

