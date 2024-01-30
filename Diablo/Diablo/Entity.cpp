#include "Entity.h"
#include"EntityManager.h"
#include"TextureManager.h"


Entity::Entity(const string& _name, const EntityType& _type, const int _life, const Vector2f& _size, const float _speed) : IManageable(_name)
{
	Register();
	type = _type;
	life = _life;
	size = _size;
	speed = _speed;
	shape = new RectangleShape(_size);
}

Entity::~Entity()
{
	if (!shape)return;
	delete shape;
	shape = nullptr;
}

void Entity::Register()
{
	EntityManager::GetInstance().Add(id, this);
}

void Entity::InitTexture(const string& _path)
{
	TextureManager::GetInstance().Load(shape, _path);
}


void Entity::Update()
{
}



