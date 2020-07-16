#pragma once
#include"Defination.hpp"
#include"SFML/Audio.hpp"

class SoundEffect
{
public:
	SoundEffect();
	~SoundEffect();

	void playEatingSound();
	void playLevelUpSound();
	void playSnakeHitSound();
	void playTurnSound();
	void playWallHitSound();
private:
	sf::SoundBuffer eatingSound_buf;
	sf::SoundBuffer levelUpSound_buf;
	sf::SoundBuffer SnakeHitSound_buf;
	sf::SoundBuffer TurnSound_buf;
	sf::SoundBuffer WallHitSound_buf;
	sf::Sound eatingSound;
	sf::Sound levelUpSound;
	sf::Sound SnakeHitSound;
	sf::Sound TurnSound;
	sf::Sound WallHitSound;

};