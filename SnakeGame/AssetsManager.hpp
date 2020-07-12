#pragma once
#include<map>
#include<iostream>
#include"SFML/Graphics.hpp"
#include"SFML/Audio.hpp"

class AssetsManager
{
public:
	AssetsManager();
	~AssetsManager();

	void loadTexture(std::string name, std::string fileName);
	sf::Texture& getTexture(std::string name);

	void loadFont(std::string name, std::string fileName);
	sf::Font& getFont(std::string name);

	void loadSound(std::string name, std::string fileName);
	sf::SoundBuffer& getSound(std::string name);
private:
	std::map<std::string, sf::Texture> texture;
	std::map<std::string, sf::Font> font;
	std::map<std::string, sf::SoundBuffer> sound;
};

