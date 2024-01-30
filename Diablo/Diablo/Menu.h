#pragma once
#include"IManageable.h"
#include"MenuElement.h"
#include<vector>
#include<SFML/Graphics.hpp>
#include"Button.h"

using namespace sf;
using namespace std;

class Menu : public IManageable<string>
{
	vector<MenuElement*> elements;
	bool wantsToQuit;
	RectangleShape* background;
public:
	void SetWantsToQuit(bool _wantsToQuit)
	{
		wantsToQuit = _wantsToQuit;
	}
public:
	Menu(const string& _id, const string& _backGroundPath, vector<MenuElement*> _element);
	~Menu();

private:
	virtual void Register() override;
	void UpdateElement(RenderWindow& _window);
	void DrawElements(RenderWindow& _window);

public:
	void Open(RenderWindow& _window);
};

