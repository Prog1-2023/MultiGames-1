#include "Projectile.h"

Projectile::Projectile(Shape* _shape, MouvementComponent _move, int _damage):MovingEntitie(_shape,_move)
{
	damage = _damage;
}
