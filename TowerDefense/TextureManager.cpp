#include "TextureManager.h"

void TextureManager::LoadTexture(Shape* _shape, const string& _texturePath)
{
	TextureData* textureData = Get(_texturePath);

	if (!textureData)
	{
		textureData = new TextureData(_texturePath);
		textureData->setSmooth(true);
	}
	
	_shape->setTexture(textureData);
}
