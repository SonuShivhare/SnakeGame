#pragma once
#include"Defination.hpp"
#include"SFML/Audio.hpp"
#include"Game.hpp"

class SoundEffect
{
public:
	SoundEffect(GameDataRef data);
	~SoundEffect();
	void playEatingSound();
private:
	GameDataRef data;
	sf::Sound eatingSound;
};