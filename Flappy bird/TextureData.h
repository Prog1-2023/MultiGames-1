#pragma once
#include "IManagable.h"

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class TextureData : public Texture, public IManagable<string>
{

public:
	TextureData(const string& _path);

	virtual void Register() override;
};

