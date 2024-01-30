#pragma once

#include "IManagable.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class TextureData : public Texture, public IManagable<string>
{
	
public:
	TextureData(const string& _path);

private:
	virtual void Register() override;
};