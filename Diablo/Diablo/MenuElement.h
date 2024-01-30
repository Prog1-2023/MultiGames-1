#pragma once
#include<SFML/Graphics.hpp>


using namespace sf;
using namespace std;

class MenuElement
{
public:
	virtual void Update(RenderWindow& _window) = 0;
	virtual vector<Drawable*>  GetDrawables() = 0;
};



