#pragma once
#include<SFML/Graphics.hpp>
#include"MouvementComponent.h"
#include"ColissionComponent.h"
using namespace sf;

class Entitie
{
protected:
	Shape* shape;
	ColissionComponent collision;

public:
	Entitie(Shape* _shape);

};

