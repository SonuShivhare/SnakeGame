#pragma once
#include<map>
#include<iostream>
#include"SFML/Graphics.hpp"

class AssetsManager
{
public:
	AssetsManager();
	~AssetsManager();

	void loadTexture(std::string name, std::string fileName);
	sf::Texture& getTexture(std::string name);

	void loadFont(std::string name, std::string fileName);
	sf::Font& getFont(std::string name);

private:
	std::map<std::string, sf::Texture> texture;
	std::map<std::string, sf::Font> font;
};

