#pragma once
#include "SFML/Graphics.hpp"
#include "TextureManager.h"
#include "IManagable.h"

using namespace std;

enum EntityType
{
	ENTITY_NONE,
	ENTITY_PLAYER,
	ENTITY_PIPE,
	ENTITY_GROUND,
};

class Entity : public IManagable<string>
{
protected:
	EntityType type;
	Vector2f position;
	Shape* shape;
	bool isAlive;

public:
	void SetPosition(const Vector2f& _position)
	{
		position = _position;
	}
	EntityType GetType() const
	{
		return type;
	}
	Vector2f GetPosition() const
	{
		return position;
	}
	Shape* GetShape() const
	{
		return shape;
	}
	bool GetIsAlive() const
	{
		return isAlive;
	}
public:
	Entity(const string& _name, const EntityType& _type, const bool _isAlive, const Vector2f& _position, const Vector2f& _size, const string& _path);
	~Entity();

public:
	virtual void Register() override;

	void InitTexture(const string& _path);

	virtual void Update();
};
