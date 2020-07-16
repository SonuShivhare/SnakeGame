#include "SoundEffect.hpp"

SoundEffect::SoundEffect()
{
	eatingSound_buf.loadFromFile(Eating_Sound_FilePath);
	levelUpSound_buf.loadFromFile(Level_Up_Sound_FilePath);
	SnakeHitSound_buf.loadFromFile(SnakeBody_hit_Sound_FilePath);
	TurnSound_buf.loadFromFile(Turn_Sound_FilePath);
	WallHitSound_buf.loadFromFile(Wall_Hit_Sound_FilePath);

	eatingSound.setBuffer(eatingSound_buf);
	levelUpSound.setBuffer(levelUpSound_buf);
	SnakeHitSound.setBuffer(SnakeHitSound_buf);
	TurnSound.setBuffer(TurnSound_buf);
	WallHitSound.setBuffer(WallHitSound_buf);
}

SoundEffect::~SoundEffect()
{
}

void SoundEffect::playEatingSound()
{
	eatingSound.play();
}

void SoundEffect::playLevelUpSound()
{
	levelUpSound.play();
}

void SoundEffect::playSnakeHitSound()
{
	SnakeHitSound.play();
}

void SoundEffect::playTurnSound()
{
	TurnSound.play();

}

void SoundEffect::playWallHitSound()
{
	WallHitSound.play();
}
