#include "SoundEffect.hpp"

SoundEffect::SoundEffect()
{
	eatingSound_bu.loadFromFile(Eating_Sound_FilePath);
	eatingSound.setBuffer(eatingSound_bu);
}

SoundEffect::~SoundEffect()
{
}

void SoundEffect::playEatingSound()
{
	eatingSound.play();
}