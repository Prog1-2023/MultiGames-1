#include "TextureManager.h"

void TextureManager::Load(Shape* _shape, const string& _path, const bool _isRepeated, const bool isSmooth)
{

	TextureData* _textureData = Get(_path);

	if (!_textureData)
	{
		_textureData = new TextureData(_path);
		if (!_textureData->loadFromFile(_path))
		{
			cerr << "La texture n'a pas ete correctement chargee ! " << endl;
		}

		_textureData->setRepeated(_isRepeated);
		_textureData->setSmooth(isSmooth);

		Add(_path, _textureData);
	}

	_shape->setTexture(_textureData);
}

