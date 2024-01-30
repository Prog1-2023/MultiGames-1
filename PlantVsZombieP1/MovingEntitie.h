#pragma once
#include"MouvementComponent.h"
#include"Entitie.h"
class MovingEntitie: public Entitie
{
	MouvementComponent move;

public:
	MovingEntitie(Shape* _shape, MouvementComponent _move);
};

