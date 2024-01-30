#include "TextureManager.h"

void TextureManager::Load(Shape* _shape, const string& _path, const bool _isRepeated, const bool _isSmooth)
{
	TextureData* _textureData = Get(_path);

	if (!_textureData)
	{
		_textureData = new TextureData(_path);
		if (!_textureData->loadFromFile(_path))
		{
			cerr << "texture non charger" << endl;
		}

		_textureData->setRepeated(_isRepeated);
		_textureData->setSmooth(_isSmooth);

	}

	_shape->setTexture(_textureData);
}