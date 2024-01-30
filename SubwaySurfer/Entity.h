#pragma once
#include "IManagable.h"

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class EntityManager;

enum EntityType
{
   PLAYER,HUNTER,WALL,COIN,BOOSTER
};

class Entity : public IManagable<string>
{
protected:
    Vector2f position;
    Shape* shape;
private:
    EntityType type;

public:
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

public:
    Entity(const string& _name, const EntityType& _type, const Vector2f& _position, const Vector2f& _size, const string& _path);
    ~Entity();

private:
    void Register() override;

protected:
    void InitTexture(const string& _path);
    void SetOriginAtMiddle();

public:
    virtual void Update();
};

