#pragma once

#include "Singleton.h"
#include "IManager.h"
#include "TextureData.h"

using namespace std;

class TextureManager : public Singleton<TextureManager>, public IManager<string, TextureData>
{

public:
	void LoadTexture(Shape* _shape, const string& _texturePath);
};