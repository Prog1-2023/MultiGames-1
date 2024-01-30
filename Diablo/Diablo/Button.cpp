#include "Button.h"


Button::Button(const string& _text, const string& _path, const function<void()>& _onClick, const Vector2f& _position) : MenuElement()
{
	text = new Text();
	text->setString(_text);
	font = new Font();
	if (!font->loadFromFile(_path))
	{
		cerr << "Erreur la font a mal ete chargee !" << endl;
		return;
	}
	text->setFont(*font);
	text->setOrigin(text->getGlobalBounds().width / 2, text->getGlobalBounds().height / 2);
	text->setPosition(_position);
	text->setFillColor(Color::Black);
	Vector2f _size = text->getGlobalBounds().getSize() + Vector2f(20.0f, 20.0f);
	button = new RectangleShape(_size);
	button->setOrigin(button->getGlobalBounds().width / 2, button->getGlobalBounds().height / 2);
	button->setPosition(_position);
	onClick = _onClick;

}

Button::~Button()
{
	delete button;
	delete text;
	delete font;
}

void Button::Update(RenderWindow& _window)
{
}

vector<Drawable*> Button::GetDrawables()
{
	vector<Drawable*> _drawables;
	_drawables.push_back(button);
	_drawables.push_back(text);
	return _drawables;
}

void Button::Click(RenderWindow& _window)
{
	if (button->getGlobalBounds().contains(Vector2f(Mouse::getPosition(_window))))
	{
		if (onClick)
		{
			onClick();

		}
	}
}


