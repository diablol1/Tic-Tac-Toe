#include "TextureCache.h"

bool TextureCache::loadFromFile(const std::string& _name, const std::string & _path)
{
	sf::Texture tmpTexture;
	tmpTexture.loadFromFile(_path);

	for (const auto& texture : textures)
	{
		if (texture.first == _name)
		{
			std::cout << "Texture manager couldn't add texture with this same name: " +
				_name << std::endl;
			return  false;
		}
	}

	textures[_name] = tmpTexture;

	for (const auto& path : paths)
	{
		if (path == _path)
		{
			std::cout << "Texture manager couldn't add this same texture: " +
				_path << std::endl;
			return false;
		}
	}
	paths.push_back(_path);

	return true;
}

void TextureCache::loadTextures()
{
	loadFromFile("emptyField", "img/emptyField.png");
	loadFromFile("circleField", "img/circleField.png");
	loadFromFile("crossField", "img/crossField.png");
}