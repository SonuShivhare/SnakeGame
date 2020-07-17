#include "AssetsManager.hpp"

AssetsManager::AssetsManager()
{
}

AssetsManager::~AssetsManager()
{
}

void AssetsManager::loadTexture(std::string name, std::string fileName)
{
	sf::Texture tex;
	if (!tex.loadFromFile(fileName))
	{
		std::cout << name << "can't be loaded" << std::endl;
	}
	else
	{
		this->texture[name] = tex;
	}
}

sf::Texture& AssetsManager::getTexture(std::string name)
{
	return this->texture.at(name);
}

void AssetsManager::loadFont(std::string name, std::string fileName)
{
	sf::Font fonts;
	if (!fonts.loadFromFile(fileName))
	{
		std::cout << name << "can't be loaded" << std::endl;
	}
	else
	{
		this->font[name] = fonts;
	}
}

sf::Font& AssetsManager::getFont(std::string name)
{
	return this->font.at(name);
}