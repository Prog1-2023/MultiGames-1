#include "Pea.h"
#include"Projectile.h"
Pea::Pea(Shape* _shape):Plant(_shape)
{
	price = 100;
	cooldown = 2.0f;
}

void Pea::Update()
{
	CircleShape* _projectile = new CircleShape(15.0f);//taille d'une case
	_projectile->setPosition(shape->getPosition());
	new Projectile(_projectile, , 15);
}
