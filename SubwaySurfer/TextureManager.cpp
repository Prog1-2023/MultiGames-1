#include "TextureManager.h"

#include <iostream>

void TextureManager::Load(Shape* _shape, const string& _path)
{
	if (_path == "") return;
	TextureData* _textureData = Get(_path);

	if (!_textureData)
	{
		_textureData = new TextureData(_path);

		if (!_textureData->loadFromFile(_path))
		{
			cerr << "La texture n'a pas été correctement chargée !" << endl;
		}
	}

	_shape->setTexture(_textureData);
}
