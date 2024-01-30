#include "TextureData.h"
#include "TextureManager.h"

TextureData::TextureData(const string& _path) : Texture(), IManagable(_path)
{
	if (!loadFromFile(_path))
	{
		cerr << "Erreur lors du chargement de la texture (" << _path << ")!" << endl;
	}
	Register();
}

void TextureData::Register()
{
	TextureManager::GetInstance()->Add(id, this);
}