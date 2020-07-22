#pragma once
#include"State.hpp"
#include"Defination.hpp"
#include"Snake.hpp"
#include"Food.hpp"

class Level_02 : public State
{
public:
	Level_02(GameDataRef data, int score);
	~Level_02();

	void init() override;
	void handleInput() override;
	void update() override;
	void draw() override;
private:
	GameDataRef data;
	Snake snake;
	Food food;
	sf::Sprite grassBackground;
	sf::Sprite StoneBorder;
	sf::Sprite pauseButton;
	sf::Clock clk;
	float timePerFrame;
	float timer;
	float delay;
	float BounusFoodTimer;
	float BounsFoodDelay;
	bool isMouseButtonReleased;
};

