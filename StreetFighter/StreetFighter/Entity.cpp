#include "Entity.h"
#include "EntityManager.h"



Entity::Entity(sf::Shape* _shape, const sf::Vector2f _position,
	const EntityType& _type, const std::string& _filePath)
{
	shape = _shape;
	type = _type;

	InitShape(_position);
	InitTexture(_filePath);
	Register();
}

Entity::~Entity()
{
	delete shape;
	shape = nullptr;
	delete texture;
	texture = nullptr;
}

void Entity::Register()
{
	EntityManager::GetInstance().AddEntity(this);
	id = EntityManager::GetInstance().GetEntityIndex(this);
}

void Entity::InitTexture(const std::string& _filePath)
{
	if (!texture->loadFromFile(_filePath))
	{
		std::cerr << "EEREUR loading texture Entity" << std::endl;
	}
	shape->setTexture(texture);
}
void Entity::InitShape(const sf::Vector2f _position)
{
	shape->setPosition(_position);
}
