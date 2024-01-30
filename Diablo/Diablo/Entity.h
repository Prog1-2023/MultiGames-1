#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"EntityType.h"
#include"IManageable.h"

using namespace sf;
using namespace std;

class EntityManager;

class Entity : public IManageable<string>
{
    string name;
    EntityType type;
    Vector2f size;
protected:
    RectangleShape* shape;
    float speed;
    int life;

public:
    void SetShapePosition(const Vector2f& _position)
    {
        shape->setPosition(_position);
    }
    RectangleShape* GetShape()const
    {
        return shape;
    }
    EntityType GetType()const
    {
        return type;
    }
    int GetLife()const
    {
        return life;
    }

public:
    Entity(const string& _name, const EntityType& _type, const int _life, const Vector2f& _size, const float _speed);
    ~Entity();

private:
    virtual void Register()override;

public:
    virtual void Update();
    void InitTexture(const string& _path);
};


