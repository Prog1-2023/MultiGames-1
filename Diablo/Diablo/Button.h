#pragma once
#include"MenuElement.h"
#include<functional>
#include<iostream>

class Button : public MenuElement
{
	RectangleShape* button;
	Text* text;
	Font* font;
	function<void()> onClick;

public:
	Button(const string& _text, const string& _path, const function<void()>& _onClick, const Vector2f& _position);
	~Button();
public:
	virtual void Update(RenderWindow& _window) override;
	virtual vector<Drawable*>  GetDrawables() override;
	void Click(RenderWindow& _window);
};



