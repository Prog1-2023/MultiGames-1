#include "Menu.h"
#include"MenuManager.h"
#include"TextureManager.h"


Menu::Menu(const string& _id, const string& _backGroundPath, vector<MenuElement*> _element) : IManageable(_id)
{
	Register();
	elements = _element;
	wantsToQuit = false;
	background = new RectangleShape(Vector2f(1200.0f, 800.0f));
	TextureManager::GetInstance().Load(background, _backGroundPath);
}

Menu::~Menu()
{
	for (MenuElement* _element : elements)
	{
		delete _element;
	}
	delete background;
}

void Menu::Register()
{
	MenuManager::GetInstance().Add(id, this);
}

void Menu::UpdateElement(RenderWindow& _window)
{
	for (MenuElement* _element : elements)
	{
		_element->Update(_window);
	}
}

void Menu::DrawElements(RenderWindow& _window)
{
	_window.draw(*background);
	for (MenuElement* _element : elements)
	{
		vector<Drawable*> _drawables = _element->GetDrawables();
		for (Drawable* _drawable : _drawables)
		{
			_window.draw(*_drawable);
		}
	}
}

void Menu::Open(RenderWindow& _window)
{
	while (_window.isOpen() && !wantsToQuit)
	{
		Event _event;
		while (_window.pollEvent(_event))
		{
			if (_event.type == Event::Closed)
			{
				_window.close();
			}
			if (_event.type == Event::MouseButtonPressed)
			{
				for (MenuElement* _element : elements)
				{
					Button* _button = dynamic_cast<Button*>(_element);
					if (_button)
					{
						_button->Click(_window);
					}
				}
			}
		}
		UpdateElement(_window);
		_window.clear();
		DrawElements(_window);
		_window.display();
	}
	wantsToQuit = false;
}


