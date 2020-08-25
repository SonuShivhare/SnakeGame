#include "SoundEffect.hpp"

SoundEffect::SoundEffect()
{
	eatingSound_buf.loadFromFile(Eating_Sound_FilePath);
	SnakeHitSound_buf.loadFromFile(SnakeBody_hit_Sound_FilePath);
	WallHitSound_buf.loadFromFile(Wall_Hit_Sound_FilePath);

	eatingSound.setBuffer(eatingSound_buf);
	SnakeHitSound.setBuffer(SnakeHitSound_buf);
	WallHitSound.setBuffer(WallHitSound_buf);
}

SoundEffect::~SoundEffect()
{
}

void SoundEffect::playEatingSound()
{
	eatingSound.play();
}

void SoundEffect::playSnakeHitSound()
{
	SnakeHitSound.play();
}

void SoundEffect::playWallHitSound()
{
	WallHitSound.play();
}
