#include "SoundEffect.hpp"

SoundEffect::SoundEffect(GameDataRef data) : data(data)
{
	this->data->assets.loadSound("eatingSonud", Eating_Sound_FilePath);
}

SoundEffect::~SoundEffect()
{
}

void SoundEffect::playEatingSound()
{
	eatingSound.setBuffer(this->data->assets.getSound("eatingSonud"));
	eatingSound.play();
}