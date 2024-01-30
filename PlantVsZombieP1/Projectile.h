#pragma once
#include "MovingEntitie.h"
#include"LivingEntite.h"
class Projectile:public MovingEntitie
{
	int damage;

public:
	Projectile(Shape* _shape,MouvementComponent _move,int _damage);
};

