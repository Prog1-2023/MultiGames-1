#include "TextureManager.h"
#include <iostream>

void TextureManager::Load(Shape* _shape, const string& _path, const bool _isRepeated, const bool _smooth)
{
	TextureData* _textureData = Get(_path);

	if (!_textureData)
	{
		_textureData = new TextureData(_path);
		if (!_textureData->loadFromFile(_path))
		{
			cerr << "La texture n'a pas été correctement chargée" << endl;
		}

		_textureData->setRepeated(_isRepeated);
		_textureData->setSmooth(_smooth);

		_textureData->SetID(_path);
	}

	_shape->setTexture(_textureData);
}
