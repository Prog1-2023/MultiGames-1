#pragma once
#include"Singleton.h"
#include"IManager.h"
#include<map>
#include<iostream>
#include<SFML/Graphics.hpp>
#include"TextureData.h"


using namespace std;
using namespace sf;

class TextureManager : public Singleton<TextureManager>, public IManager<string, TextureData>
{
public:
	void Load(Shape* _shape, const string& _path, const bool _isRepeated = false, const bool isSmooth = true);
};

