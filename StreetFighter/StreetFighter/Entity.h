#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

enum EntityType
{
	ETT_CHARACTER, ETT_WALL
};

class Entity
{
	sf::Shape* shape;
	sf::Texture* texture;
	EntityType type;
	int id;

public:
	Entity(sf::Shape* _shape, const sf::Vector2f _position,
		const EntityType& _type, const std::string& _filePath );
	virtual ~Entity();

public:
	sf::Shape* GetShape()const
	{
		return shape;
	}

private:
	void Register();
	void InitTexture(const std::string& _filePath);
	void InitShape(const sf::Vector2f _position);

};


