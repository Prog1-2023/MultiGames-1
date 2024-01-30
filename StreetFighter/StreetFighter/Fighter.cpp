#include "Fighter.h"



Fighter::Fighter(MovementComponent* _movement) : Entity(/*TODO*/)
{
	movement = _movement;
}

Fighter::~Fighter()
{
	delete movement;
	movement = nullptr;
}
