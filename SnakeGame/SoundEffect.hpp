#pragma once
#include"Defination.hpp"
#include"SFML/Audio.hpp"

class SoundEffect
{
public:
	SoundEffect();
	~SoundEffect();
	void playEatingSound();
private:
	sf::SoundBuffer eatingSound_bu;
	sf::Sound eatingSound;
};