#include "MovingEntitie.h"

MovingEntitie::MovingEntitie(Shape* _shape, MouvementComponent _move):Entitie(_shape)
{
	move = _move;
}
