#pragma once
#include "Entity.h"
#include "MovementComponent.h"

enum FighterName
{
	LAURA, ZANGLIEF
};


class Fighter : public Entity
{
	MovementComponent* movement;


public:
	Fighter(MovementComponent* _movement);
	~Fighter() override;
};

