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
			cerr << "La texture n'a pas �t� correctement charg�e !" << endl;
		}
	}

	_shape->setTexture(_textureData);
}
