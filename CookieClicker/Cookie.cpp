#include "Cookie.h"
#include "CookieManager.h"

Cookie::Cookie(const int _id, const Vector2f& _position) : IManagable(_id)
{
	Register();

	shape = new CircleShape(50.0f);
	shape->setPosition(_position);
	shape->setFillColor(Color::Red);
}

Cookie::~Cookie()
{
	delete shape;
}


void Cookie::Register()
{
	CookieManager::GetInstance().Add(id, this);
}