#pragma once
#include"Entitie.h"
class Plant:public Entitie
{
protected:
	int price;
	float cooldown;

public:
	Plant(Shape* _shape);
};

