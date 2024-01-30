#pragma once
#include "IManagable.h"
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;
using namespace sf;

class TextureData : public Texture, public IManagable<string>
{
public:
	TextureData(const string& _path);

private:
	virtual void Register() override;
};

